#include <stdio.h>
#include <stdbool.h>
#include "mprend/threading.h"
#include "mprend/debugger.h"
#include "mprend/video.h"
#include "mprend/mem.h"

#undef main

ThreadFunction testThread(ThreadParams params) {
    while(true) {
        printf("Test Thread Triggered.\n");
        udelay(1000);
    }
}

void main() {
    // Screen.
    MPScreen screen1;
    MPR_InitVideo("Test MPRenderer", 800,600, &screen1);

    // Init Mem.
    MPR_DebuggerInit();
    MPR_InitMemory();

    MPThread* tThread = MPInitThread(testThread, NULL);
    MPStartThread(tThread);

    // Print version.
    char* ver = MPR_GetVersion();
    printf("%s\n", ver);

    while(true) {
        udelay(100);
    }
}