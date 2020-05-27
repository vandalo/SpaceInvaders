#pragma once

#include "Entity.h"
#include "Animation.h"
#include "Point.h"


class CPlayer : public Entity
{
	const float m_speed = 100.0f;

public:
	CPlayer(bool active = true);
	update_status Update(const float deltaTime) override;
	update_status PreUpdate(const float deltaTime) override;
	bool CleanUp();

private:
	void GetInput() override;
	void Move(float dt);

	Animation* m_currentAnimation;
	Animation m_static;
	Animation m_forward;
	Animation m_left;
	Animation m_right;

	Point<float> m_position;
	float m_speedX;
	float m_speedY;
};

