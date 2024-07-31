/**
 * @file video.wii.c
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
 * @param w Screen Width.
 * @param h Screen Height.
 * @param pScreen Pointer to Screen.
 */
int MPR_InitVideo(char* title, int w, int h, MPScreen* pScreen) {
    // Size is forced 640x480.
    MPSize scrnSize;
    scrnSize.w=640;
    scrnSize.h=480;
    
    // Setup the screen size.
    pScreen->window = NULL;
    pScreen->renderer = NULL;
    pScreen->screenSize = scrnSize;
    pScreen->title = title;

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