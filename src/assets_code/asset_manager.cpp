#include "../assets_code/asset_manager.h"
#include "../enums.h"

// Central object for accessing image assets
inline ImageManager imageManager;

ImageManager ManageAssets(FunctionStates state)
{
    if (state == FunctionStates::LOAD_ASSETS)
    {
        LoadAssets();
        LoadSounds();
        ////Set window icon

        return imageManager;
    }

    if (state == FunctionStates::UNLOAD_ASSETS)
    {
        UnloadAssets();
        UnloadSounds();
    }
}

void LoadAssets()
{
    imageManager.playerSkin = LoadTexture(TextFormat("assets/spr_character.png"));
}
void LoadSounds()
{

}

void UnloadAssets()
{
    imageManager.unloadAll();
    // UNLOAD NOISE MAP
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