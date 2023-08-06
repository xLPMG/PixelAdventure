#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<stack>
#include<map>

#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"

class MovementComponent
{
private:
	sf::Sprite& sprite;

	float maxSpeed;
	sf::Vector2f speed;
	sf::Vector2f acceleration;
	sf::Vector2f deceleration;
public:
	MovementComponent(sf::Sprite& sprite, float maxSpeed);
	virtual ~MovementComponent();

	const sf::Vector2f& getSpeed() const;

	void move(const float x, const float y, const float dt);
	void update(const float &dt);
};