#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxSpeed) 
	: sprite(sprite), maxSpeed(maxSpeed)
{
}

MovementComponent::~MovementComponent()
{
}

const sf::Vector2f& MovementComponent::getSpeed() const
{
	return speed;
}

void MovementComponent::move(const float x, const float y, const float dt)
{
	speed.x = maxSpeed * x;
	speed.y = maxSpeed * y;
	sprite.move(speed * dt);
}

void MovementComponent::update(const float& dt)
{
}
