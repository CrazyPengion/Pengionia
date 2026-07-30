#ifndef WORLD_H
#define WORLD_H

#include <string>					// world naming
#include "../enums.h"				// understandable DrawTextureEx parameters
#include "../noise_map/noise_map.h" // noise map generator

Texture2D getMap(int worldSeed, Vector2int screenSize, float screenScale, Vector2 playerPos);

class World
{
private:
	int seed;
public:
	std::string name;

	void GenerateSeed()
	{
		seed = GetRandomValue(0, 1000000000);
	}

	void DisplayMap(Vector2 playerPos, float screenScale)
	{
		// get noise map
		Texture2D noiseMap;
		noiseMap = getMap(seed, Vector2int{ GetScreenWidth(), GetScreenHeight() }, screenScale, playerPos);

		// display noise map
		DrawTextureEx(noiseMap, DrawSettings::ORIGIN,
			DrawSettings::NO_ROTATION, DrawSettings::TILE_SIZE * screenScale, WHITE);
	}                         // change this part to follow player ^
};		In the function above: 1. Change get noise map into a one time function, currently it creates tons of new images (and/or unload it each time) (the larger plan is to load a part of the noise map and then display a part of that part in a chunk like system) 2. fix the map notfilling the screen in y axis

#endif