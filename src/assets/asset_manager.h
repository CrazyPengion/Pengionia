#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "../enums.h"

// called externally
void ManageAssets(FunctionStates state);

// called internally
void LoadAssets();
void LoadSounds();

void UnloadAssets();
void UnloadSounds();

#endif