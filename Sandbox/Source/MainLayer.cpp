#include "MainLayer.h"
#include <stdio.h>
#include "Tiny.h"
#include <3ds.h> 

MainLayer::MainLayer() {
    // Use the correct namespace capitalization
    Tiny3d::Vec2 vec(1.0f, 2.0f);
    printf("Vector: %.1f, %.1f\n", vec.x, vec.y);

    printf("\nPress START to exit.");
}

MainLayer::~MainLayer() {

}

void MainLayer::OnUpdate(float ts) {
    hidScanInput();
    u32 kDown = hidKeysDown();

    if (kDown & KEY_START) {
        // TODO: Signal application to stop
    }
}

void MainLayer::OnRender() {

}