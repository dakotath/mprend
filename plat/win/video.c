/**
 * @file video.wii.c
 */
#ifdef PLATFORM_WIN

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <windows.h>

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
    scrnSize.w = w;
    scrnSize.h = h;

    // Initialize everything.
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL2 could not be initialized!\n"
               "SDL2 Error: %s\n", SDL_GetError());
        return MPR_ERROR_VINIT;
    }

    // Initialize SDL2_ttf
    TTF_Init();

    // Create base.
    MPWindow *window = SDL_CreateWindow(title,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          scrnSize.w, scrnSize.h,
                                          SDL_WINDOW_SHOWN);
    pScreen->window = window;
    MPRenderer *renderer = SDL_CreateRenderer(pScreen->window, -1, SDL_RENDERER_ACCELERATED);
    pScreen->renderer = renderer;

    // Setup the screen size.
    pScreen->screenSize = scrnSize;
    pScreen->title = title;

    // Ok.
    return MPR_ERROR_VOK;
}


#endif