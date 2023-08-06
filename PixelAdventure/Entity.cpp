#include "Entity.h"
void Entity::initVariables()
{
	movementComponent = NULL;
}
Entity::Entity() {
	initVariables();
	
}

Entity::~Entity() {
}

void Entity::setTexture(sf::Texture& texture)
{
	sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxSpeed)
{
	movementComponent = new MovementComponent(sprite, maxSpeed);
}

void Entity::setPosition(const float x, const float y)
{
	sprite.setPosition(x, y);
}

void Entity::move(const float& dt, const float x, const float y)
{
	if (movementComponent) {
		movementComponent->move(x, y, dt);
	}
}

void Entity::update(const float& dt)
{
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
