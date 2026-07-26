#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "../enums.h" // Get different function states
//DEBUG start
#include <iostream>
//DEBUG end

class Player
{
public:
	int hp{ 100 };
	Vector2 pos{ 0.0f,0.0f };

	float velocity{ 20.0f };
	
	void checkMovement(Player& player, PlayerStates movementType)
	{
		if (movementType == PlayerStates::MOVEMENT_WALK)
		{

		}

		else if (movementType == PlayerStates::MOVEMENT_FLY)
		{
			if (IsKeyDown(KEY_W))
				player.pos.y -= 20.0f;
			if (IsKeyDown(KEY_S))
				player.pos.y += 20.0f;
			if (IsKeyDown(KEY_A))
				player.pos.x -= 20.0f;
			if (IsKeyDown(KEY_D))
				player.pos.x += 20.0f;
		}

		// DEBUG start
		//std::cout << player.pos.x << " | " << player.pos.y << '\n';
		// DEBUG end
	}

	void displayPlayer(Texture2D skin, float screenScale) // 16 * 32
	{
		// Get offset from center - half player size in each direction
		int xOffset{ GetScreenWidth() / (GetScreenWidth() / 8) };
		int yOffset{ GetScreenHeight() / (GetScreenHeight() / 8) * 2 };

		// Calculate final position (center) based on screen size & offset
		Vector2 position{ (GetScreenWidth() / 2 - xOffset),(GetScreenHeight() / 2 - yOffset)};

		DrawTextureEx(skin, position, 0.0f, screenScale, WHITE);
	}
};

#endif