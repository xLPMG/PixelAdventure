#include "Player.h"

void Player::initVariables()
{
}

void Player::initComponents()
{
	createMovementComponent(100.f);
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
