#include "Application.h"
#include "ModuleFadeToBlack.h"
#include "ModuleScreenManager.h"
#include "Screen.h"

ModuleScreenManager::ModuleScreenManager()
	: m_activeScreen(nullptr)
{

}

bool ModuleScreenManager::Start()
{
	return true;
}

update_status ModuleScreenManager::PreUpdate(float deltaTime)
{
	m_activeScreen->PreUpdate(deltaTime);
	return UPDATE_CONTINUE;
}

update_status ModuleScreenManager::Update(const float deltaTime)
{
	m_activeScreen->InternalUpdate(deltaTime);
	m_activeScreen->Update(deltaTime);
	return UPDATE_CONTINUE;
}

update_status ModuleScreenManager::PostUpdate(float deltaTime)
{
	m_activeScreen->PostUpdate(deltaTime);
	return UPDATE_CONTINUE;
}

bool ModuleScreenManager::CleanUp()
{
	return true;
}

void ModuleScreenManager::LoadScreen(Screen* screen)
{
	App->fade->FadeToBlack(screen, nullptr, 3.0f);
	screen->Start();

	if (m_activeScreen)
	{
		m_activeScreen->CleanUp();
		RELEASE(m_activeScreen);
	}
	m_activeScreen = screen;
}
