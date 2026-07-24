#ifndef ENUMS_H
#define ENUMS_H
#include <cstdint>

enum class FunctionStates : uint8_t 
{
    LOAD_ASSETS,
    UNLOAD_ASSETS
};

enum class BlockType : uint8_t
{
    GRASS,
    DIRT,
    ROCK // Natural
    //STONE // Modified / Small
};

#endif