#ifndef ENUMS_H
#define ENUMS_H
#include <cstdint>
#include "raylib.h"

enum class FunctionStates : uint8_t 
{
    LOAD_ASSETS,
    UNLOAD_ASSETS
};

enum class PlayerStates : uint8_t
{
    MOVEMENT_WALK,
    MOVEMENT_FLY
};

namespace DrawSettings
{
    constexpr float NO_ROTATION = 0.0f;
    constexpr float TILE_SIZE = 8.0f;
    constexpr Vector2 ORIGIN = Vector2{ 0.0f, 0.0f };
};

enum class BlockType : uint8_t
{
    GRASS,
    DIRT,
    ROCK // Natural
    //STONE // Modified / Small
};

enum class MenuPage : uint8_t
{
    START_PLAYING,
    SELECT_MODE,
    CREATING_WORLD,
    SETTINGS,
    NONE,
    PAUSE
};

#endif