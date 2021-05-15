#include "framework.h"
#include "Object.h"

Object::Object(const char* texturePath, const Vector2f& position)
{
	texture = new Texture;
	texture->loadFromFile(texturePath);
	setTexture(*texture);
	setPosition(position);
	setOrigin(this->getTexture()->getSize().x / 2.f, this->getTexture()->getSize().y / 2.f);
}

const bool& Object::isActive() const
{
	return active;
}

void Object::SetActive(const bool& active)
{
	this->active = active;
}

void Object::MoveUpdate(const Vector2f& direction)
{
	moveDir = direction;
	move(moveDir * deltaTime * moveSpeed);

	// TODO : smooth movement
}

void Object::Update(const float& deltaTime)
{
	this->deltaTime = deltaTime;
}
