#include "init_engine.h"
#include "raylib.h"

void InitEngine()
{
	InitGameWindow();
	//InitSound();
}

void InitGameWindow()
{
	InitWindow(800, 450, "My Game");
	//Set window icon
}

/*
void initSound()
{
	 InitAudioDevice();
	 // add different audio threads (for multiple sounds at the same time)? <==< does it work in web?
}
*/