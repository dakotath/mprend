/**
 * @file mem.c
 * Memory handler.
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Other platforms.
#ifdef PLATFORM_WIN
#include <windows.h>
#endif
#ifdef PLATFORM_WII
#include <stdbool.h>
#endif

// Internal.
#include "mprend/version.h"
#include "mprend/mem.h"

// Variables.
long long __usedMem = 0;
long long __totalMem = 0;

char* __formatFileSize(long long bytes) {
    static char result[50]; // Static buffer to hold the formatted string

    if (bytes < 1024) {
        sprintf(result, "%lld B", bytes);
    } else if (bytes < 1024 * 1024) {
        sprintf(result, "%.2f KB", (float)bytes / 1024);
    } else if (bytes < 1024 * 1024 * 1024) {
        sprintf(result, "%.2f MB", (float)bytes / (1024 * 1024));
    } else {
        sprintf(result, "%.2f GB", (float)bytes / (1024 * 1024 * 1024));
    }

    return result;
}


// Get mem size.
int MPR_InitMemory() {
    // Platforms.
    printf("Please wait, Getting Memory Info.\n");
    #if defined(PLATFORM_WIN)
        MEMORYSTATUSEX statex;

        statex.dwLength = sizeof(statex);

        if (GlobalMemoryStatusEx(&statex)) {
            printf("Total RAM: %s\n", __formatFileSize(statex.ullTotalPhys));
        } else {
            printf("GlobalMemoryStatusEx failed\n");
            return 1;
        }
        __totalMem = statex.ullTotalPhys;
    #elif defined(PLATFORM_WII)
        long long validMem = 0;
        while(true) {
            void* testAlloc = malloc(validMem);
            if(testAlloc == NULL) break;
            printf("\x1b[3;0H");
            printf("Successfully Allocated: %s    ", __formatFileSize(validMem));
            free(testAlloc);
            validMem+=500;
        }
        printf("\n");
        __totalMem=validMem;
    #else
        return 2;
    #endif
    return 0;
}