/**
 * @file threading.win.c
 * Windows Threading.
 */
#ifdef PLATFORM_WIN

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>

/**
 * @brief Thread Information.
 * @paragraph p1es this is used to initialize threads into a controllable struct (Ex: stop, start, and wait functions).
 * 
 * @param func The function of the thread you are initializing
 * @param params Any parameters you need to pass to the thread function (Leave NULL if unused).
 */
MPThread *MPInitThread(ThreadFunction func, ThreadParams params) {
    MPThread *thread = malloc(sizeof(MPThread));
    if (thread == NULL) {
        printf("Failed to allocate memory for MPThread.\n");
        return NULL;
    }

    thread->func = func;
    thread->params = params;
    thread->threadHandle = CreateThread(NULL, 0, thread->func, thread->params, 0, NULL);

    return thread;
}

/**
 * @brief Starting Threads.
 * @paragraph p1esd To start threads, use StartThread to startup your thread.
 * 
 * @param *thread A ThreadInfo that can be created with InitThread().
 */
void MPStartThread(MPThread* thread) {
    if (thread->threadHandle != NULL) {
        ResumeThread(thread->threadHandle);
    }
}

/**
 * @brief Waiting For Threads to Finish.
 * @paragraph p1ad If you want to wait for a thread to finish up, use this.
 * 
 * @param *thread A ThreadInfo that can be created with InitThread().
 */
void MPWaitForThread(MPThread* thread) {
    if (thread->threadHandle != NULL) {
        WaitForSingleObject(thread->threadHandle, INFINITE);
    }
}

/**
 * @brief Destroying Threads.
 * @paragraph p1aw To clear threads, use this function to wipe the thread to NULL.
 * 
 * @param *thread The thread you want to clear.
 */
void MPDestroyThread(MPThread* thread) {
    if (thread->threadHandle != NULL) {
        CloseHandle(thread->threadHandle);
    }
}

#endif