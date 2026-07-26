#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "raylib.h"
#include "../enums.h"

class ImageManager
{
public:
	Texture2D playerSkin;

	void unloadAll()
	{
		UnloadTexture(playerSkin);
	}
};

// called externally
ImageManager ManageAssets(FunctionStates state);

// called internally
void LoadAssets();
void LoadSounds();

void UnloadAssets();
void UnloadSounds();

#endif