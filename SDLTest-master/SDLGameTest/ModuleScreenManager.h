#pragma once

#include "Application.h"
#include "Module.h"

#include <vector>

class Screen;

class ModuleScreenManager : public Module
{
public:
	ModuleScreenManager();

	bool Start();
	update_status PreUpdate(float deltaTime);
	update_status Update(const float deltaTime);
	update_status PostUpdate(float deltaTime);
	bool CleanUp();
	void LoadScreen(Screen* screen);


private:
	Screen* m_activeScreen;
	
};

