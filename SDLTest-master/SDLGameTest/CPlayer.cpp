#include "CPlayer.h"
#include "Application.h"

#include "ModuleRender.h"
#include "ModuleInput.h"

CPlayer::CPlayer(bool active) 
	: Entity()
	, m_speedX(0.0f)
	, m_speedY(0.0f)
	, m_position(0,0)
{
	m_static.frames.push_back(App->textures->Load("Assets/Player/spaceship.png"));

	m_forward.frames.push_back(App->textures->Load("Assets/Player/Animation/6.png"));
	m_forward.frames.push_back(App->textures->Load("Assets/Player/Animation/7.png"));

	m_left.frames.push_back(App->textures->Load("Assets/Player/Animation/2.png"));
	m_left.frames.push_back(App->textures->Load("Assets/Player/Animation/8.png"));
	m_left.frames.push_back(App->textures->Load("Assets/Player/Animation/4.png"));

	m_right.frames.push_back(App->textures->Load("Assets/Player/Animation/5.png"));
	m_right.frames.push_back(App->textures->Load("Assets/Player/Animation/1.png"));
	m_right.frames.push_back(App->textures->Load("Assets/Player/Animation/3.png"));

	m_render = { 0, 0, 128, 128 };
	m_currentAnimation = &m_right;
}

update_status CPlayer::Update(const float deltaTime)
{
	m_render.x = static_cast<int>(m_position.x);
	m_render.y = static_cast<int>(m_position.y);
	App->renderer->Blit(m_currentAnimation->GetCurrentFrame(), m_render);
	return UPDATE_CONTINUE;
}

update_status CPlayer::PreUpdate(const float deltaTime)
{
	GetInput();
	Move(deltaTime);
	return UPDATE_CONTINUE;
}

bool CPlayer::CleanUp()
{
	return false;
}

void CPlayer::GetInput()
{
	bool moving = false;
	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT) 
	{
		m_speedX = m_speed;
		m_currentAnimation = &m_right;
		moving = true;
	}
	else if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		m_speedX = (-m_speed);
		m_currentAnimation = &m_left;
		moving = true;
	}
	else
	{
		m_speedX = 0.0f;
	}
	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		m_speedY = (-m_speed);
		m_currentAnimation = &m_forward;
		moving = true;
	}
	else if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		m_speedY = m_speed;
		m_currentAnimation = &m_static;
		moving = true;
	}
	else
	{
		m_speedY = 0.0f;
	}
	
	if(!moving)
	{
		m_currentAnimation = &m_static;
	}
}

void CPlayer::Move(float dt)
{
	m_position.x += m_speedX * dt;
	m_position.y += m_speedY * dt;
}
