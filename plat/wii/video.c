/**
 * @file video.grrlib.c
 */
#ifdef PLATFORM_WII

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <ogcsys.h>
#include <grrlib.h>
#include <wiiuse/wpad.h>
#include <fat.h>

#include "mprend/version.h"
#include "mprend/video.h"

/**
 * @brief Init the Video System.
 */
int MPR_InitVideo(int w, int h) {
    // Size is forced 640x480.
    w=640;
    h=480;

    // Init the Wii Platform.
    WPAD_Init();
    GRRLIB_Init();

    // Wii Specific.
    int sdInit = fatInitDefault();
    if(sdInit != 1) {
        return MPR_ERROR_VINIT;
    }

    return MPR_ERROR_VOK;
}

#endif