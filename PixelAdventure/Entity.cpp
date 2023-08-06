#include "Entity.h"
void Entity::initVariables()
{
	sprite = NULL;
	texture = NULL;
	movementSpeed = 100.f;
}
Entity::Entity() {
	initVariables();
	
}

Entity::~Entity() {
	delete this->sprite;
}

void Entity::createSprite(sf::Texture* texture)
{
	this->texture = texture;
	sprite->setTexture(*this->texture);
}

void Entity::move(const float& dt, const float x, const float y)
{
	if(sprite) sprite->move(x*movementSpeed*dt,y*movementSpeed*dt);
}

void Entity::update(const float& dt)
{
}

void Entity::render(sf::RenderTarget* target)
{
	if (sprite) target->draw(*sprite);
}
