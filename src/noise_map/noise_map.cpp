#include "noise_map.h"
#include "../custom_structs.h"

Vector2int noiseSize{ 1500,1500 };

Texture2D generateNoiseMap()
{
	Image noiseImage = GenImagePerlinNoise(noiseSize.x, noiseSize.y, 0, 0, 60.0f);
	noiseImage = makeTilesAt255Red(noiseImage);
	Texture2D noiseTexture = LoadTextureFromImage(noiseImage);
	SetTextureFilter(noiseTexture, TEXTURE_FILTER_POINT);
	
	return noiseTexture;
}

Image makeTilesAt255Red(Image inputImage)
{
	Color* pixels = LoadImageColors(inputImage);
	for (int i = 0; i < noiseSize.x * noiseSize.y; i++)
	{
		if (pixels[i].r > 200)
		{
			pixels[i] = RED;
		}
	}
	
	Image modifiedNoise{};
	modifiedNoise.data = pixels;
	modifiedNoise.width = noiseSize.x;
	modifiedNoise.height = noiseSize.y;
	modifiedNoise.mipmaps = 1;
	modifiedNoise.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;

	return modifiedNoise;
}