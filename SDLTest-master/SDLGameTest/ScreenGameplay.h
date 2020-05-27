#ifndef __ModuleSceneMapAfrica_H__
#define __ModuleSceneMapAfrica_H__

#include "Screen.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL.h>
#include <SDL_image.h>
#elif defined(__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#endif

using namespace std;


class ScreenGameplay : public Screen
{

public:
	ScreenGameplay(bool active = true);
	~ScreenGameplay();
	bool Start();
	update_status Update(const float deltaTime) override;
	bool CleanUp();

private:
	SDL_Texture* m_background;
};

#endif // __ModuleSceneMapAfrica_H__