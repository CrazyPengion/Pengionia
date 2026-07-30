#include "raylib.h"					// Texture2D
#include "../enums.h"				// understandable multiplicators
#include "../custom_structs.h"      // Vector2int
#include "../noise_map/noise_map.h" // access noise map generator

Texture2D getMap(int worldSeed, Vector2int screenSize, float screenScale, Vector2 playerPos)
{
	// convert pixels to tiles
	screenSize.x /= DrawSettings::TILE_SIZE * screenScale;
	screenSize.y /= DrawSettings::TILE_SIZE * screenScale;
	playerPos.x /= DrawSettings::TILE_SIZE * screenScale;
	playerPos.y /= DrawSettings::TILE_SIZE * screenScale;

	Texture2D noiseMap = LoadTextureFromImage(generateNoiseMap(worldSeed, screenSize, screenScale, playerPos));
	return noiseMap;
}