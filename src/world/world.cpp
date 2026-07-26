#include "FastNoiseLite.h"
#include "raylib.h"
#include "../noise_map/noise_map.h"
#include "../custom_structs.h"

Texture2D getMap(int worldSeed, Vector2int screenSize)
{
	return generateNoiseMap(worldSeed, screenSize);
}