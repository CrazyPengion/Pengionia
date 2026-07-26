#ifndef ENUMS_H
#define ENUMS_H
#include <cstdint>

enum class FunctionStates : uint8_t 
{
    LOAD_ASSETS,
    UNLOAD_ASSETS,

    PLAYER_WALK,
    PLAYER_FLY // add swim / crawl?
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