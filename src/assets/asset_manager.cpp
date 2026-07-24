#include "../assets/asset_manager.h"
#include "../enums.h"

void ManageAssets(FunctionStates state)
{
    if (state == FunctionStates::LOAD_ASSETS)
    {
        LoadAssets();
        LoadSounds();
        ////Set window icon
    }

    if (state == FunctionStates::UNLOAD_ASSETS)
    {
        UnloadAssets();
        UnloadSounds();
    }
}

void LoadAssets()
{

}
void LoadSounds()
{

}

void UnloadAssets()
{

}
void UnloadSounds()
{

}

// init ground images();
// init other images();
// init sounds();
// std::vector<Sound> gameSounds;

/*
STUFF LIKE THIS HERE:

for (int i = 0; i < 16; i++) // fills groundImages with tile_grass_0 to _15     // works only after InitWindow()
{
    groundImages[i] = LoadTexture(TextFormat("assets/tile_grass_%d.png", i));
}
*/