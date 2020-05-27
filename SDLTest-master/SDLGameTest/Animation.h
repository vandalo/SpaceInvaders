#pragma once
#include <vector>
#include "Globals.h"
#include "ModuleTextures.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL.h>
#include <SDL_image.h>
#elif defined(__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#endif

using namespace std;

class Animation
{
public:
	bool loop = true;
	float speed = 0.3f;
	vector<SDL_Texture*> frames;

private:
	float current_frame = 0.0f;
	int loops = 0;

public:
	Animation()
	{}

	Animation(const Animation& anim) : loop(anim.loop), speed(anim.speed), frames(anim.frames)
	{}

	SDL_Texture* GetCurrentFrame()
	{
		float last_frame = (float)frames.size();

		current_frame += speed;
		if (current_frame >= last_frame)
		{
			current_frame = (loop) ? 0.0f : MAX(last_frame - 1.0f, 0.0f);
			loops++;
		}

		return frames[(int)current_frame];
	}

	bool Finished() const
	{
		return loops > 0;
	}

	void Reset()
	{
		current_frame = 0.0f;
		loops = 0;
	}
};
