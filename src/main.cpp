// Pengionia: A 2D open world survival game.

#include "raylib.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

//DEBUG start
#include <iostream>
//DEBUG end

#include "enums.h"				  // Get Enums
#include "main.h"				  // Forward Declarations for functions in main.cpp
#include "engine/init_engine.h"   // Initialize window, sound engine
#include "assets_code/asset_manager.h" // Load / Unload Assets
#include "game_loop/game_loop.h"  // Get definition for StartGameLoop();
#include "player/player.h"        // Get definition for player class
#include "displaying/coordinate_converter.h" // Get world to the screen coordinate converter
#include "custom_structs.h"		  // Get custom structs
#include "world/world.h"          // Get map generator

Player player;
World world;
inline ImageManager imageManager;
float screenScale{ 4.0f }; // TODO will be used later to allow different screen sizes

int main()
{
	InitEngine();
	imageManager = ManageAssets(FunctionStates::LOAD_ASSETS); // Load images

	StartGameLoop();
	return 0;
}

void UpdateDrawFrame()
{
	//LOGIC
	player.CheckMovement(player, PlayerStates::MOVEMENT_FLY); // DEBUG: FLY


	//DISPLAYING
	BeginDrawing();
	ClearBackground(BLACK);

	// Display world
	world.DisplayMap(player.pos, screenScale);

	// Display player
	player.Display(imageManager.playerSkin, screenScale);
	EndDrawing();
}