#include <stdio.h>
#include <stdbool.h>
#include "mprend/debugger.h"
#include "mprend/video.h"
#include "mprend/mem.h"

#undef main

void main() {
    // Screen.
    MPScreen screen1;
    MPR_InitVideo("Test MPRenderer", 800,600, &screen1);

    // Init Mem.
    MPR_DebuggerInit();
    MPR_InitMemory();

    // Print version.
    char* ver = MPR_GetVersion();
    printf("%s\n", ver);

    while(true) {}
}