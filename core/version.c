/**
 * @file version.c
 * Contains utils for getting version and support information.
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Internal.
#include "mprend/version.h"

/**
 * @brief Gets The Engine Version as a String.
 */
char* MPR_GetVersion() {
    // Allocate more memory to catch problem.
    char* _verStrM = malloc(__MPR_VLEN*2);

    // Put the version into the string.
    // Major, Minor, Patch, Codename.
    sprintf(_verStrM, "V%d.%d.%d \"%s\"", __MPR_VMAJ,__MPR_VMIN,__MPR_PACH,__MPR_CNAM);

    // Check the length of the version.
    int _verLen = strlen(_verStrM);
    if(_verLen > __MPR_VLEN) {
        // Free memory.
        free(_verStrM);

        // Error.
        return "ER:VTooLng";
    }

    // Return Version.
    return _verStrM;
}