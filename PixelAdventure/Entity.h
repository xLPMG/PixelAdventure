#pragma once

#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"

class Entity
{
private:
	sf::RectangleShape shape;
	float movementSpeed;
public:
	Entity();
	virtual ~Entity();

	virtual void move(const float& dt, const float x, const float y);
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

