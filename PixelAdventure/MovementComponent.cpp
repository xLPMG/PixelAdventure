#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxSpeed, float acceleration, float deceleration)
	: sprite(sprite), maxSpeed(maxSpeed), acceleration(acceleration), deceleration(deceleration)
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
	speed.x += acceleration * x;
	speed.y += acceleration * y;
}

void MovementComponent::update(const float& dt)
{
	if(speed.x >= 0.f){
		if (speed.x > maxSpeed) speed.x = maxSpeed;
		speed.x -= deceleration;
		if (speed.x < 0.f) speed.x = 0.f;
	}
	else {
		if (speed.x < -maxSpeed) speed.x = -maxSpeed;
		speed.x += deceleration;
		if (speed.x > 0.f) speed.x = 0.f;
	}
	if (speed.y >= 0.f) {
		if (speed.y > maxSpeed) speed.y = maxSpeed;
		speed.y -= deceleration;
		if (speed.y < 0.f) speed.y = 0.f;
	}
	else {
		if (speed.y < -maxSpeed) speed.y = -maxSpeed;
		speed.y += deceleration;
		if (speed.y > 0.f) speed.y = 0.f;
	}


	//no more movement changes below this
	sprite.move(speed * dt);
}
