#include "raylib.h"
#include "../custom_structs.h"

// provide a world coordinate and the screen center (player), to get the screen coordinates (where to display it)
Vector2 WorldToScreenPos(Vector2 worldPos, Vector2 centerPos)
{
	Vector2 screenPos;
	screenPos = Vector2{ (worldPos.x - centerPos.x + (GetScreenWidth() / 2)), (worldPos.y - centerPos.y + (GetScreenHeight() / 2)) };
	return screenPos;			// ScreenWidth/2 and ScreenHeight/2 account for that the player is in the middle and not 0,0 (top left corner)
}

Vector2int WorldToScreenPosInt(Vector2int worldPos, Vector2int centerPos)
{
	Vector2int screenPos;
	screenPos = Vector2int{ (worldPos.x - centerPos.x + (GetScreenWidth() / 2)), (worldPos.y - centerPos.y + (GetScreenHeight() / 2)) };
	return screenPos;
}