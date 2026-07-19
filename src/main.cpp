// Pengionia: A 2D open world survival game.

#include "raylib.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

//DEBUG start
#include <iostream>
//DEBUG end

#include "main.h"		   // Forward Declarations for functions in main.cpp
#include "init_engine.h"   // Initialize window, sound engine
#include "init_assets.h"   // Initialize images and sounds
#include "game_loop.h"	   // Get definition for StartGameLoop();
#include "unload_assets.h" // Unload Assets

int main()
{
	InitEngine();
	InitAssets();

	StartGameLoop();
	return 0;
}

void UpdateDrawFrame()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawText("Hello, World!", 10, 10, 20, DARKGRAY);
	EndDrawing();
}