#ifndef __MODULERENDER_H__
#define __MODULERENDER_H__

#include "Module.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL.h>
#include <SDL_image.h>
#elif defined(__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#endif


#include "Globals.h"

struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PreUpdate(float deltaTime);
	update_status Update(const float deltaTime);
	update_status PostUpdate(float deltaTime);
	bool CleanUp();

	bool Blit(SDL_Texture* texture, SDL_Rect rect);
	bool Print(unsigned int idFont, const char* text, int x, int y, bool center = true);
	bool DrawQuad(const SDL_Rect& rect, unsigned int r, unsigned int g, unsigned int b, unsigned int a, bool use_camera = true);


public:
	SDL_Renderer* renderer = nullptr;
	SDL_Rect camera;
};

#endif // __MODULERENDER_H__