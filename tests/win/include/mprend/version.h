/**
 * @file version.h
 * Version header.
 */
#ifndef MPR_VERSION_H
#define MPR_VERSION_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Curent Version.
#define __MPR_VMAJ 1                // Version Major.
#define __MPR_VMIN 0                // Version Minor.
#define __MPR_PACH 0                // Version Patch.
#define __MPR_CNAM "Pretty Sauce"   // Version Codename.
#define __MPR_VLEN 1024             // Maximum length of the version string.

// Functions.
char* MPR_GetVersion();

// Support.
#ifdef PLATFORM_WII
    #define DOES_SUPPORT_THREADS
    #define DOES_SUPPORT_VIDEO
    //#define DOES_SUPPORT_AUDIO
#endif

#ifdef PLATFORM_WIN
    #define DOES_SUPPORT_THREADS
    //#define DOES_SUPPORT_VIDEO
    //#define DOES_SUPPORT_AUDIO
#endif

// MPR_VERSION_H
#endif