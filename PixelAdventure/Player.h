#pragma once
#include "Entity.h"
class Player :
	public Entity
{
private:
	void initVariables();
public:
	Player(float x, float y, sf::Texture& textureSheet);
	virtual ~Player();

	virtual void update(const float& dt);
};

