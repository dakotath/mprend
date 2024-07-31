/**
 * @file threading.h
 * Header for threading.
 */
#ifndef MPR_THREADING_H
#define MPR_THREADING_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Internal.
#include "mprend/version.h"

// Platform Support.
#ifdef PLATFORM_WII
    #include <unistd.h>
    
    // Internal Wait.
    #define udelay(ms) usleep(ms * 1000)

    // Thread Types.
    typedef void* ThreadFunction;
    typedef void* ThreadParams;
    typedef lwp_t ThreadHandle;
#endif

// Windows Support.
#ifdef PLATFORM_WIN
    #include <windows.h>

    // Internal Wait.
    #define udelay(ms) Sleep(ms)

    #define ThreadFunction DWORD WINAPI
    #define ThreadParams LPVOID
    typedef HANDLE ThreadHandle;
#endif

// Thread Structure.
typedef struct {
    ThreadFunction func;
    ThreadParams params;
    ThreadHandle threadHandle;
} MPThread;

#endif