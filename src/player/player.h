#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "../enums.h"
//DEBUG start
#include <iostream>
//DEBUG end

class Player
{
public:
	int hp{ 100 };
	Vector2 pos{ 0.0f,0.0f };

	float velocity{ 20.0f };
	
	void calculateMovement(Player& player, FunctionStates movementType)
	{
		if (movementType == FunctionStates::PLAYER_WALK)
		{

		}

		else if (movementType == FunctionStates::PLAYER_FLY)
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
};

#endif