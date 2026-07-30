#include "FastNoiseLite.h"
#include "raylib.h"
#include "../noise_map/noise_map.h"
#include "../custom_structs.h"

Texture2D getMap(int worldSeed, Vector2int screenSize, Vector2 playerPos)
{
	// Divide all sizes trough 8, as that's the tile size
	screenSize.x /= 8;
	screenSize.y /= 8;
	playerPos.x /= 8;
	playerPos.y /= 8;

	Texture2D noiseMap = LoadTextureFromImage(generateNoiseMap(worldSeed, screenSize, playerPos, false));
	return noiseMap;
}