#include <3ds.h>
#include <stdio.h>
#include <tiny.h> // The master header!

int main(int argc, char* argv[]) {
    //gfxInitDefault();
    //consoleInit(GFX_TOP, NULL);

    // Testing our master header
    printf("Engine Version: %s\n", Tiny3d::GetVersion());

    // Testing our Math component through the master header
    Tiny3d::Vector3 vec(1.0f, 2.0f, 3.0f);
    printf("Vector initialized at: %.1f, %.1f\n", vec.x, vec.y);

    printf("\nPress START to exit.");

    /*while (aptMainLoop()) {
        hidScanInput();
        if (hidKeysDown() & KEY_START) break;
        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();*/
    return 0;
}
