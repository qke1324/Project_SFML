#pragma once
#include "Object.h"
class Player : public Object
{
public:
	Player();
	Player(const char* texturePath, const Vector2f& position);
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;
	virtual ~Player() = default;

private:

	float speed = 100.f;

public:

	void SetSpeed(const float& speed);
};

