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
	float acceleration;
	float deceleration;

	sf::Vector2f speed;

public:
	MovementComponent(sf::Sprite& sprite, float maxSpeed, 
		float acceleration, float deceleration);
	virtual ~MovementComponent();

	const sf::Vector2f& getSpeed() const;

	const bool isIdle() const;

	void move(const float x, const float y, const float dt);
	void update(const float &dt);
};