#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "CPlayer.h"

#include "ScreenGameplay.h"

ScreenGameplay::ScreenGameplay(bool active)
	: m_background(nullptr)
{
}

bool ScreenGameplay::Start()
{
	m_background = App->textures->Load("Assets/Background/background.jpg");
	m_entities.push_back(new CPlayer());
	return true;
}

update_status ScreenGameplay::Update(const float deltaTime)
{
	App->renderer->Blit(m_background, m_position);
	
	Screen::Update(deltaTime);
	return UPDATE_CONTINUE;
}

bool ScreenGameplay::CleanUp()
{
	LOG("Unloading Gameplay");
	App->textures->Unload(m_background);
	return true;
}

ScreenGameplay::~ScreenGameplay()
{}
