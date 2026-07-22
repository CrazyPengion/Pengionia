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
//DEBUG end

#include "enums.h"				  // Get Enums
#include "main.h"				  // Forward Declarations for functions in main.cpp
#include "engine/init_engine.h"   // Initialize window, sound engine
#include "assets/asset_manager.h" // Load / Unload Assets
#include "game_loop/game_loop.h"  // Get definition for StartGameLoop();
#include "player/player.h"        // Get definition for player class
#include "displaying/coordinate_converter.h" // Get world to the screen coordinate converter
#include "custom_structs.h"		  // Get custom structs

Player player;

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
	Vector2 textPos{ WorldToScreenPos(debugObjectPos, debugMovingPos) };
	DrawText("Hello, World!", textPos.x, textPos.y, 40, DARKGRAY);
	EndDrawing();
	DebugMove();
}

void DebugMove()
{
	if (IsKeyDown(KEY_W))
		player.pos.y -= 3.0f;
	if (IsKeyDown(KEY_S))
		player.pos.y += 3.0f;
	if (IsKeyDown(KEY_A))
		player.pos.x -= 3.0f;
	if (IsKeyDown(KEY_D))
		player.pos.x += 3.0f;
	std::cout << player.pos.x << " | " << player.pos.y << '\n';
	debugMovingPos = player.pos;
}