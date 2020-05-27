#include "Globals.h"
#include "Application.h"
#include "ModuleFont.h"
#include "ModuleTextures.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL.h>
#include <SDL_image.h>
#elif defined(__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#endif


ModuleFont::ModuleFont()
{}

// Destructor
ModuleFont::~ModuleFont()
{}

unsigned int ModuleFont::LoadMedia(const char* filePath, const char* formatFont, unsigned int fontWidth, unsigned int fontHeigth, unsigned int initY)
{
	//Loading success flag
	bool success = true;
	Font font;
	//Load splash image
	font.surface = App->textures->Load(filePath);
	font.y = initY;
	if (font.surface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", filePath, SDL_GetError());
		success = false;
	}
	font.width = fontWidth;
	font.heigth = fontHeigth;
	for (unsigned int i = 0; formatFont[i] != '\0'; i++) {
		font.fontMap[formatFont[i]] = i * fontWidth;
	}
	fonts.push_back(font);
	return static_cast<unsigned int>(fonts.size() - 1);
}