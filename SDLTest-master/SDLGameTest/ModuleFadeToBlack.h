#ifndef __MODULEFADETOBLACK_H__
#define __MODULEFADETOBLACK_H__

#include "Module.h"
#include "Globals.h"

class Screen;

class ModuleFadeToBlack : public Module
{
public:
	ModuleFadeToBlack(bool start_enabled = true);
	~ModuleFadeToBlack();

	bool Start();
	update_status Update(const float deltaTime);
	void FadeToBlack(Screen* module_on, Screen* module_off = nullptr, float time = 1.0f);
	bool isFading() const;

private:

	unsigned int start_time = 0;
	unsigned int total_time = 0;
	bool fading_in = true;
	Screen* module_on = nullptr;
	Screen* module_off = nullptr;
};

#endif // __MODULEFADETOBLACK_H__