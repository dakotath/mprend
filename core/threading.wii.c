/**
 * @file threading.wii.c
 * LibOGC Threading.
 */
#ifdef PLATFORM_WII

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ogcsys.h>

#include "mprend/threading.h"
#include "mprend/version.h"

/**
 * @brief Thread Information.
 * @paragraph p1es this is used to initialize threads into a controllable struct (Ex: stop, start, and wait functions).
 * 
 * @param func The function of the thread you are initializing
 * @param params Any parameters you need to pass to the thread function (Leave NULL if unused).
 */
MPThread *MPInitThread(ThreadFunction func, ThreadParams params) {
    MPThread *thread = malloc(sizeof(MPThread));
    #ifdef DOES_SUPPORT_THREADS
        if (thread == NULL) {
            printf("Failed to allocate memory for MPThread.\n");
            return NULL;
        }

        thread->func = func;
        thread->params = params;
        LWP_CreateThread(&thread->threadHandle, func, NULL, NULL, 0, 80);
    #endif
    return thread;
}

/**
 * @brief Starting Threads.
 * @paragraph p1esd To start threads, use StartThread to startup your thread.
 */
void MPStartThread(MPThread* thread) {
    #ifdef DOES_SUPPORT_THREADS
        LWP_ResumeThread(thread->threadHandle);
    #endif
}

/**
 * @brief Waiting For Threads to Finish.
 * @paragraph p1ad If you want to wait for a thread to finish up, use this.
 */
void MPWaitForThread(MPThread* thread) {
    #ifdef DOES_SUPPORT_THREADS
        if(LWP_JoinThread(thread->threadHandle, NULL) != 0)
        {
            printf("Failed to join the thread.\n");
        }
    #endif
}

/**
 * @brief Destroying Threads.
 * @paragraph p1aw To clear threads, use this function to wipe the thread to NULL.
 * 
 * @param *thread The thread you want to clear.
 */
void MPDestroyThread(MPThread* thread) {
    free(thread);
}

#endif