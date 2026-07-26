#ifndef NOISEMAP_H
#define NOISEMAP_H

#include "raylib.h"
#include "../custom_structs.h"

Texture2D generateNoiseMap(int worldSeed, Vector2int screenSize);
Image debugModifyImage(Image inputImage, Vector2int screenSize);

#endif