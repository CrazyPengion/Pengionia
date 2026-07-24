// Pengionia: A 2D open world survival game.

#include "raylib.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

//DEBUG start
#include <iostream>
Vector2 debugObjectPos{ 0.0f,0.0f };
Vector2 debugMovingPos{ 0.0f,0.0f };
void DebugMove();
Texture2D noise2;
//DEBUG end

#include "enums.h"				  // Get Enums
#include "main.h"				  // Forward Declarations for functions in main.cpp
#include "engine/init_engine.h"   // Initialize window, sound engine
#include "assets/asset_manager.h" // Load / Unload Assets
#include "game_loop/game_loop.h"  // Get definition for StartGameLoop();
#include "player/player.h"        // Get definition for player class
#include "displaying/coordinate_converter.h" // Get world to the screen coordinate converter
#include "custom_structs.h"		  // Get custom structs
#include "noise_map/noise_map.h"  // Get noise map utility

Player player;

int main()
{
	InitEngine();
	ManageAssets(FunctionStates::LOAD_ASSETS);

	StartGameLoop();
	return 0;
}

void UpdateDrawFrame()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	Vector2 textPos{ WorldToScreenPos(debugObjectPos, debugMovingPos) };
	DrawText("Press E for noise map.", static_cast<int>(textPos.x), static_cast<int>(textPos.y), 40, DARKGRAY);
	DrawTextureEx(noise2, WorldToScreenPos(Vector2{ (0.0f,0.0f) }, debugMovingPos), 0.0f, 2.0f, WHITE); // set scale as a
																				// global variable - game scale
																				// add separate UI scale
	EndDrawing();

	DebugMove();
}

// DEBUG start
void DebugMove()
{
	if (IsKeyDown(KEY_W))
		player.pos.y -= 20.0f;
	if (IsKeyDown(KEY_S))
		player.pos.y += 20.0f;
	if (IsKeyDown(KEY_A))
		player.pos.x -= 20.0f;
	if (IsKeyDown(KEY_D))
		player.pos.x += 20.0f;
	
	// Generate noise map
	if (IsKeyDown(KEY_E))
	{
		noise2 = generateNoiseMap();
	}

	std::cout << player.pos.x << " | " << player.pos.y << '\n';
	debugMovingPos = player.pos;
}
// DEBUG end