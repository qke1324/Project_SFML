#include "framework.h"
#include "Object.h"

Object::Object(const char* texturePath, const Vector2f& position)
{
	texture = new Texture;
	texture->loadFromFile(texturePath);
	setTexture(*texture);
	setPosition(position);
}

void Object::Update(const float& deltaTime)
{

}
