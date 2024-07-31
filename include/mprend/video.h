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

// Video Errors.
enum {
    MPR_ERROR_VOK = 0,
    MPR_ERROR_VINIT = -1,
} MPRVErrors;

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

// Platform support.
#ifdef PLATFORM_WII
    #include <grrlib.h>

    typedef GRRLIB_texImg TextureData;
    typedef GRRLIB_ttfFont FontData;
#endif

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
int MPR_InitVideo(int w, int h);