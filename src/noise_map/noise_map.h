#ifndef NOISEMAP_H
#define NOISEMAP_H

#include "raylib.h"

Texture2D generateNoiseMap(int worldSeed);
Image makeTilesAt255Red(Image inputImage);

#endif