/**
 * @file video.h
 * Video header.
 */
#ifndef MPR_VIDEO_H
#define MPR_VIDEO_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "version.h"

// Platform support.
#ifdef PLATFORM_WII
    #include <grrlib.h>

    typedef GRRLIB_texImg TextureData;
    typedef GRRLIB_ttfFont FontData;

    typedef void* MPWindow;
    typedef void* MPRenderer;
#endif
#ifdef PLATFORM_WIN
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>

    typedef SDL_Texture TextureData;
    typedef TTF_Font FontData;

    typedef SDL_Window MPWindow;
    typedef SDL_Renderer MPRenderer;

    typedef float f32;
#endif

// Standard types.
typedef struct {
    int x;
    int y;
} MPVector2;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} MPVector3;
typedef struct {
    int w;
    int h;
} MPSize;
typedef struct {
    int r;
    int g;
    int b;
    int a;
} MPColor;

// Screen.
typedef struct {
    MPWindow* window;
    MPRenderer* renderer;
    MPSize screenSize;
    char* title;
} MPScreen;

// Generic structures.
typedef struct {
    // Data.
    TextureData* tex;

    // Misc.
    MPSize texSize;
    MPColor texColor;
    MPVector2 texPos;
} MPTexture;

typedef struct {
    // Data.
    FontData* font;

    // Misc.
    int fontSize;
} MPFont;

// Functions.
int MPR_InitVideo(char* title, int w, int h, MPScreen* pScreen);

// MPR_VIDEO_H
#endif