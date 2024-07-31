#include <stdio.h>
#include <stdbool.h>
#include "mprend/video.h"
#include "mprend/mem.h"

#undef main

void main() {
    // Screen.
    MPScreen screen1;
    MPScreen screen2;

    // Init Mem.
    MPR_InitMemory();
    MPR_InitVideo("Test MPRenderer", 800,600, &screen1);
    MPR_InitVideo("Test MPRenderer 2", 640,480, &screen2);

    // Print version.
    char* ver = MPR_GetVersion();
    printf("%s\n", ver);

    while(true) {}
}