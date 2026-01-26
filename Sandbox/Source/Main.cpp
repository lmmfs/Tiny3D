#include <3ds.h>   // Required for 3DS entry point and hardware
#include <stdio.h>
#include <tiny.h>

int main(int argc, char* argv[]) {
    // 1. Initialize the 3DS graphics and console
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    // 2. Use your engine code
    printf("Engine Version: %s\n", Tiny3d::GetVersion());

    // Use the correct namespace capitalization
    tiny3d::Vec2 vec(1.0f, 2.0f);
    printf("Vector: %.1f, %.1f\n", vec.x, vec.y);

    printf("\nPress START to exit.");

    // 3. Main loop: The 3DS needs this to stay alive
    while (aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();

        if (kDown & KEY_START) break; // Exit to Homebrew Menu

        // Flush and swap framebuffers
        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    // 4. Cleanup and exit
    gfxExit();
    return 0;
}
