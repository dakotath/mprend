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
MPThread *InitThread(ThreadFunction func, ThreadParams params) {
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

#endif