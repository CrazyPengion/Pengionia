#include "../engine/init_engine.h"
#include "../player/player.h"
#include "raylib.h"

void InitEngine()
{
	InitGameWindow();
	//InitSound();
}

void InitGameWindow()
{
	InitWindow(1920, 1080, "My Game");
}

/*
void initSound()
{
	 InitAudioDevice();
	 // add different audio threads (for multiple sounds at the same time)? <==< does it work in web?
}
*/