#ifndef WORLD_H
#define WORLD_H

#include "../noise_map/noise_map.h"
#include <string>

Texture2D getMap(int worldSeed, Vector2int screenSize, Vector2 playerPos);

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

	void Display(Player& player, float screenScale)
	{
		
	}
};

#endif