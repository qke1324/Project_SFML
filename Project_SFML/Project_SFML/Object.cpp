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

void Object::Update(const float& deltaTime)
{

}
