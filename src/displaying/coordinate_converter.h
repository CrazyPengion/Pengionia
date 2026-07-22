#ifndef COORDINATECONVERTER_H
#define COORDINATECONVERTER_H

#include "raylib.h"
#include "../custom_structs.h"

Vector2 WorldToScreenPos(Vector2 worldPos, Vector2 centerPos);
Vector2int WorldToScreenPosInt(Vector2int worldPos, Vector2int centerPos);

#endif