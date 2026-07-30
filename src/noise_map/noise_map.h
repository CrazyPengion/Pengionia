#ifndef NOISEMAP_H
#define NOISEMAP_H

#include "raylib.h"
#include "../custom_structs.h"

Image generateNoiseMap(int worldSeed, Vector2int screenSize, Vector2 playerPos, bool returnCloseMap);
Image debugModifyImage(Image inputImage, Vector2int screenSize);

#endif