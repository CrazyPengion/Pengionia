#ifndef WORLD_H
#define WORLD_H

#include "../noise_map/noise_map.h"
#include <string>

Texture2D getMap(int worldSeed, Vector2int screenSize);

class World
{
public:
	std::string name;
	int seed;
};

#endif