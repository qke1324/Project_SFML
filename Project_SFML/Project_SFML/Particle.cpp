#include "framework.h"
#include "Particle.h"

Particle::Particle()
{
}

Particle::Particle(const char* texturePath)
{
	this->texture = new Texture;
	this->texture->loadFromFile(texturePath);
	setTexture(*texture);
	setScale(0.1f, 0.1f);
	Init();
}

void Particle::Init()
{
}

void Particle::Update(const float& deltaTime)
{
	move(moveDir * deltaTime * moveSpeed);
}

void Particle::SetMoveDirection(const Vector2f& direction)
{
	this->moveDir = direction;
}

void Particle::SetMoveSpeed(const float& speed)
{
	moveSpeed = speed;
}
