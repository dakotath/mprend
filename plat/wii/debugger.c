/**
 * @file debugger.wii.c
 */
#ifdef PLATFORM_WII

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <gccore.h>
#include <ogcsys.h>
#include <wiiuse/wpad.h>
#include <fat.h>

static void *_d_xfb = NULL;
static GXRModeObj *_d_rmode = NULL;

void MPR_DebuggerInit() {
	// Obtain the preferred video mode from the system
	// This will correspond to the settings in the Wii menu
	_d_rmode = VIDEO_GetPreferredMode(NULL);

	// Allocate memory for the display in the uncached region
	_d_xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(_d_rmode));

	// Initialise the console, required for printf
	console_init(_d_xfb, 20, 20, _d_rmode->fbWidth, _d_rmode->xfbHeight, _d_rmode->fbWidth * VI_DISPLAY_PIX_SZ);

	// Set up the video registers with the chosen mode
	VIDEO_Configure(_d_rmode);

	// Tell the video hardware where our display memory is
	VIDEO_SetNextFramebuffer(_d_xfb);

	// Make the display visible
	VIDEO_SetBlack(FALSE);

	// Flush the video register changes to the hardware
	VIDEO_Flush();

	// Wait for Video setup to complete
	VIDEO_WaitVSync();
	if (_d_rmode->viTVMode & VI_NON_INTERLACE)
		VIDEO_WaitVSync();
}

// PLATFORM_WII
#endif