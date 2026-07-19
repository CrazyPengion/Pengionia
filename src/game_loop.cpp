#include "game_loop.h"
#include "main.h"
#include "raylib.h"

#if defined(PLATFORM_WEB)
    #include <emscripten.h>
#endif

// Keep the implementation out of the header
void StartGameLoop() 
{
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }
#endif
}