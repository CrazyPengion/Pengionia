// Pengionia: A 2D open world survival game.

#include "raylib.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

//DEBUG start
#include <iostream>
//DEBUG end

// Forward Declarations for functions in main.cpp
#include "main.h"
// Initialize window, sound engine
#include "init_engine.h"
// Initialize images and sounds
#include "init_assets.h"
// Get definition for StartGameLoop();
#include "game_loop.h"
// Unload Assets
#include "unload_assets.h"

int main() {
    InitEngine();
    InitAssets();

    StartGameLoop();

    UnloadAssets();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}

void UpdateDrawFrame() 
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello, World!", 10, 10, 20, DARKGRAY);
    EndDrawing();
}