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
	animationComponent->addAnimation("PRE_IDLE_LEFT", 20.f, 0, 0, 5, 0, 80, 80);
	animationComponent->addAnimation("IDLE_LEFT", 20.f, 6, 0, 9, 0, 80, 80);
	animationComponent->addAnimation("PRE_IDLE_RIGHT", 20.f, 4, 0, 9, 0, 80, 80);
	animationComponent->addAnimation("IDLE_RIGHT", 20.f, 0, 0, 3, 0, 80, 80);

	animationComponent->addAnimation("WALK_LEFT", 20.f, 3, 2, 5, 2, 80, 80);
	animationComponent->addAnimation("POST_WALK_LEFT", 20.f, 0, 2, 2, 2, 80, 80);

	animationComponent->addAnimation("WALK_RIGHT", 20.f, 0, 3, 2, 3, 80, 80);
	animationComponent->addAnimation("POST_WALK_RIGHT", 20.f, 3, 3, 5, 3, 80, 80);

	animationComponent->addAnimation("WALK_UP", 20.f, 7, 2, 7, 2, 80, 80);
	animationComponent->addAnimation("WALK_DOWN", 20.f, 8, 2, 8, 2, 80, 80);
}

Player::~Player()
{
}

void Player::update(const float& dt)
{
	movementComponent->update(dt);
	if(movementComponent->isIdle()) animationComponent->play("IDLE_LEFT", dt);
	else animationComponent->play("WALK_LEFT", dt);
}
