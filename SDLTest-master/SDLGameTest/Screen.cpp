#include "Screen.h"

Screen::Screen()
	: m_position{0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}
{

}

bool Screen::Start()
{
	return true;
}

update_status Screen::PreUpdate(float deltaTime)
{
	bool ret = UPDATE_CONTINUE;
	for (vector<Entity*>::iterator it = m_entities.begin(); it != m_entities.end() && ret == UPDATE_CONTINUE; ++it)
		if ((*it)->IsEnabled() == true)
			ret = (*it)->PreUpdate(deltaTime);
	return UPDATE_CONTINUE;
}

update_status Screen::InternalUpdate(const float deltaTime)
{
	bool ret = UPDATE_CONTINUE;
	for (vector<Entity*>::iterator it = m_entities.begin(); it != m_entities.end() && ret == UPDATE_CONTINUE; ++it)
		if ((*it)->IsEnabled() == true)
		{
			 ret = (*it)->InternalUpdate(deltaTime);
		}
	return UPDATE_CONTINUE;
}

update_status Screen::Update(const float deltaTime)
{
	bool ret = UPDATE_CONTINUE;
	for (vector<Entity*>::iterator it = m_entities.begin(); it != m_entities.end() && ret == UPDATE_CONTINUE; ++it)
		if ((*it)->IsEnabled() == true)
		{
			ret = (*it)->Update(deltaTime);
		}
	return UPDATE_CONTINUE;
}

update_status Screen::PostUpdate(float deltaTime)
{
	bool ret = UPDATE_CONTINUE;
	for (vector<Entity*>::iterator it = m_entities.begin(); it != m_entities.end() && ret == UPDATE_CONTINUE; ++it)
		if ((*it)->IsEnabled() == true)
			ret = (*it)->PostUpdate(deltaTime);
	return UPDATE_CONTINUE;
}

bool Screen::CleanUp()
{
	for (vector<Entity*>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
		RELEASE(*it);
	return true;
}

bool Screen::IsEnabled() const
{
	return active;
}

bool Screen::Enable()
{
	active = true;
	return true;
}

bool Screen::Disable()
{
	if (active == true)
		return active = !CleanUp();

	return true;
}
