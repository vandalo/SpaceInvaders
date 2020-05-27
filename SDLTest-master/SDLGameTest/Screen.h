#pragma once
#include "Globals.h"
#include <vector>
#include "Entity.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL.h>
#include <SDL_image.h>
#elif defined(__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#endif

using namespace std;

class Screen
{
public:
	Screen();
	virtual bool Start();
	virtual update_status PreUpdate(float deltaTime);
	update_status InternalUpdate(const float deltaTime);
	virtual update_status Update(const float deltaTime);
	virtual update_status PostUpdate(float deltaTime);
	bool CleanUp();
	virtual bool IsEnabled() const;
	virtual bool Enable();
	virtual bool Disable();

private:
	bool active = true;

protected:
	vector<Entity*> m_entities;
	SDL_Rect m_position;
};

