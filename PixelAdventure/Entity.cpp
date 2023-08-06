#include "Entity.h"
void Entity::initVariables()
{
	movementComponent = NULL;
}
Entity::Entity() {
	initVariables();
	
}

Entity::~Entity() {
	delete movementComponent;
}

void Entity::setTexture(sf::Texture& texture)
{
	sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxSpeed, const float acceleration, const float deceleration)
{
	movementComponent = new MovementComponent(sprite, maxSpeed, acceleration, deceleration);
}

void Entity::setPosition(const float x, const float y)
{
	sprite.setPosition(x, y);
}

void Entity::move(const float x, const float y, const float& dt)
{
	if (movementComponent) {
		movementComponent->move(x, y, dt);
	}
}

void Entity::update(const float& dt)
{
	if (movementComponent) movementComponent->update(dt);
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
