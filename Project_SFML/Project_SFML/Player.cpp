#include "framework.h"
#include "Player.h"

Player::Player()
{
	texture = new Texture;
	texture->loadFromFile("Texture/player.png");
	setTexture(*texture);
	setPosition(400.f, 300.f);
	setOrigin(this->getTexture()->getSize().x / 2.f, this->getTexture()->getSize().y / 2.f);
}

Player::Player(const char* texturePath, const Vector2f& position)
{
	texture = new Texture;
	texture->loadFromFile(texturePath);
	setTexture(*texture);
	setPosition(position);
}

void Player::SetSpeed(const float& speed)
{
	this->speed = speed;
}
