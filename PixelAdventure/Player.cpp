#include "Player.h"

void Player::initVariables()
{
}

Player::Player(float x, float y, sf::Texture& textureSheet)
{
	initVariables();
	setPosition(x,y);

	//components
	createMovementComponent(200.f, 15.0f, 5.0f);
	createAnimationComponent(textureSheet);
	animationComponent->addAnimation("IDLE_LEFT", 20.f, 6, 0, 9, 0, 80, 80);
}

Player::~Player()
{
}

void Player::update(const float& dt)
{
	movementComponent->update(dt);
	animationComponent->play("IDLE_LEFT", dt);
}
