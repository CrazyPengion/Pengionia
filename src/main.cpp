// Pengionia: A 2D open world survival game.

#include "raylib.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

void UpdateDrawFrame() {
    // Put your frame logic (Update and Draw) here
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello, World!", 10, 10, 20, DARKGRAY);
    EndDrawing();
}

int main() {
    InitWindow(800, 450, "My Game");

#if defined(PLATFORM_WEB)
    // Emscripten hijacks the loop and runs UpdateDrawFrame at 60fps
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }
#endif

    CloseWindow();
    return 0;
}