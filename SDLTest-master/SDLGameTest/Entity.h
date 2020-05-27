#pragma once

#include "Globals.h"
#include <vector>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL.h>
#include <SDL_image.h>
#elif defined(__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#endif

using namespace std;

class Entity
{
public:
	Entity(bool active = true) 
		: active(active)
		, m_render{0,0,0,0}
	{}

	virtual ~Entity()
	{}

	bool IsEnabled() const
	{
		return active;
	}

	bool Enable()
	{
		if (active == false)
			return active = Start();

		return true;
	}

	bool Disable()
	{
		if (active == true)
			return active = !CleanUp();

		return true;
	}

	virtual bool Init()
	{
		return true;
	}

	virtual bool Start()
	{
		return true;
	}

	virtual update_status PreUpdate(float deltaTime)
	{
		return UPDATE_CONTINUE;
	}

	virtual update_status Update(const float deltaTime)
	{
		return UPDATE_CONTINUE;
	}

	update_status InternalUpdate(const float deltaTime)
	{
		update_status ret = UPDATE_CONTINUE;
		for (vector<Entity*>::iterator it = m_entities.begin(); it != m_entities.end() && ret == UPDATE_CONTINUE; ++it)
			if ((*it)->IsEnabled() == true)
			{
				ret = (*it)->InternalUpdate(deltaTime);
				ret = (*it)->Update(deltaTime);
			}
		return ret;
	}

	virtual update_status PostUpdate(float deltaTime)
	{
		return UPDATE_CONTINUE;
	}

	virtual bool CleanUp()
	{
		return true;
	}

private:
	bool active;

protected:
	virtual void GetInput() {};

	SDL_Rect m_render;
	vector<Entity*> m_entities;
};

