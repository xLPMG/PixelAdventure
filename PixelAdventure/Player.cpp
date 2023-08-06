#include "Player.h"

void Player::initVariables()
{
}

void Player::initComponents()
{
	createMovementComponent(200.f, 15.0f, 5.0f);
}

Player::Player(float x, float y, sf::Texture& texture)
{
	initVariables();
	initComponents();
	setTexture(texture);
	setPosition(x,y);
}

Player::~Player()
{
}
