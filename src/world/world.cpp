#include "FastNoiseLite.h"
#include "raylib.h"
#include "../noise_map/noise_map.h"

Texture2D getMap(int worldSeed)
{
	return generateNoiseMap(worldSeed);
}