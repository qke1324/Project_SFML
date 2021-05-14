#include "Entity.h"

CEntity::CEntity()
{

}

CEntity::~CEntity()
{
	delete this->sprite;
}

void CEntity::CreateSprite(Texture* texture)
{
	this->texture = texture;
	this->sprite->setTexture(*this->texture); 
}

void CEntity::Move(const float& deltatime, const float dirX, const float dirY)
{
	if (this->sprite) {
		this->sprite->move(dirX * this->moveSpeed * deltatime, dirY * this->moveSpeed * deltatime);
	}

}
void CEntity::Update(const float& deltatime)
{


}

void CEntity::Render(RenderTarget* target)
{
	if (this->sprite) {
		target->draw(*this->sprite);
	}
}