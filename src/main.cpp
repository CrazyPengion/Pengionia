// Pengionia: A 2D open world survival game.

#include "raylib.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

//DEBUG start
#include <iostream>
//DEBUG end

#include "enums.h"				  // Enums
#include "main.h"				  // Forward Declarations for functions in main.cpp
#include "engine/init_engine.h"   // Initialize window, sound engine
#include "assets/asset_manager.h" // Load / Unload Assets
#include "game_loop/game_loop.h"  // Get definition for StartGameLoop();

int main()
{
	InitEngine();
	ManageAssets(LOAD_ASSETS);

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