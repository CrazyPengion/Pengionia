#include "noise_map.h"
#include "../custom_structs.h"
#include "FastNoiseLite.h"

Texture2D generateNoiseMap(int worldSeed, Vector2int screenSize)
{	
	// Generate noise map
	FastNoiseLite noise;
	noise.SetSeed(worldSeed);

	noise.SetNoiseType(FastNoiseLite::NoiseType_Cellular);
	noise.SetFrequency(-0.02f);
	noise.SetCellularDistanceFunction(FastNoiseLite::CellularDistanceFunction_EuclideanSq);
	noise.SetCellularReturnType(FastNoiseLite::CellularReturnType_Distance);
	noise.SetCellularJitter(1.0f);

	Image image = GenImageColor(screenSize.x, screenSize.y, BLANK);

	// Warp (improve) noise map
	FastNoiseLite warp;
	warp.SetSeed(worldSeed);
	warp.SetDomainWarpType(FastNoiseLite::DomainWarpType_OpenSimplex2);
	warp.SetDomainWarpAmp(80.0f);
	warp.SetFrequency(0.01f);

	for (int y = 0; y < screenSize.y; y++)
	{
		for (int x = 0; x < screenSize.x; x++)
		{
			float xCoord = static_cast<float>(x);
			float yCoord = static_cast<float>(y);

			// 1. Distort coordinates using warp instance
			warp.DomainWarp(xCoord, yCoord); 

			// 2. Sample noise with distorted coordinates
			float val = noise.GetNoise(xCoord, yCoord);

			// 3. Normalize value from [-1, 1] to [0, 255] for Raylib image color
			unsigned char colorVal = static_cast<unsigned char>((val + 1.0f) * 0.5f * 255.0f);
			Color color = { colorVal, colorVal, colorVal, 255 };

			ImageDrawPixel(&image, x, y, color);
		}
	}

	image = debugModifyImage(image, screenSize);
	Texture2D noiseMap = LoadTextureFromImage(image);
	UnloadImage(image);

	return noiseMap;
}

Image debugModifyImage(Image inputImage, Vector2int screenSize)
{
	Color* pixels = LoadImageColors(inputImage);
	for (int i = 0; i < screenSize.x * screenSize.y; i++)
	{
		if (pixels[i].r > 55)
		{
			pixels[i] = RED;
		}
		else if (pixels[i].r < 56 && pixels[i].r > 37)
		{
			pixels[i] = GREEN;
		}
		else 
		{
			pixels[i] = YELLOW;
		}
	}
	
	Image modifiedNoise{};
	modifiedNoise.data = pixels;
	modifiedNoise.width = screenSize.x;
	modifiedNoise.height = screenSize.y;
	modifiedNoise.mipmaps = 1;
	modifiedNoise.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;

	return modifiedNoise;
}