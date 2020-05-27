#ifndef __APPLICATION_CPP__
#define __APPLICATION_CPP__

#include<list>
#include "Globals.h"
#include "Module.h"
#include <time.h>

class ModuleRender;
class ModuleWindow;
class ModuleTextures;
class ModuleInput;
class ModuleAudio;
class ModuleFadeToBlack;
class ModuleFont;
class ModuleScreenManager;
//class ModuleCollision;
//class ModuleParticles;

class Application
{
public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

public:
	ModuleRender* renderer;
	ModuleWindow* window;
	ModuleTextures* textures;
	ModuleInput* input;
	ModuleAudio* audio;
	ModuleFadeToBlack* fade;
	ModuleFont* font;
	ModuleScreenManager* screenManager;
	//ModuleCollision* collision;
	//ModuleParticles* particles;

private:
	clock_t timer = 0;
	float deltaTime = 0;
	std::list<Module*> modules;

};

extern Application* App;

#endif // __APPLICATION_CPP__