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
#DEFINE __MPR_VMAJ 1                // Version Major.
#DEFINE __MPR_VMIN 0                // Version Minor.
#DEFINE __MPR_PACH 0                // Version Patch.
#DEFINE __MPR_CNAM "Pretty Sauce"   // Version Codename.
#DEFINE __MPR_VLEN 1024             // Maximum length of the version string.

// Funtions.
char* MPR_GetVersion();

#endif