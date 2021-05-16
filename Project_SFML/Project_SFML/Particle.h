#pragma once
#include "Object.h"

class Particle final : public Object
{
public:
	Particle();
	Particle(const char* texturePath);
	Particle(const Particle&) = delete;
	Particle& operator=(const Particle&) = delete;
	virtual ~Particle() = default;

private:

	void Init();

public:

	void Update(const float& deltaTime);
	void SetMoveDirection(const Vector2f& direction);
	void SetMoveSpeed(const float& speed);
};

