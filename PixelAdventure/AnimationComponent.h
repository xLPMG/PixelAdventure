#pragma once

#include<unordered_map>

#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"

class AnimationComponent
{
private:
	class Animation
	{
	public:
		sf::Sprite& sprite;
		sf::Texture& textureSheet;
		float speed;
		float timer;
		int width;
		int height;
		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;

		Animation(sf::Sprite& sprite, sf::Texture& textureSheet, float speed, int startFrameX, int startFrameY, int framesX, int framesY, int width, int height);

		void play(const float& dt);

		void reset();
	};
	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::unordered_map<std::string, Animation*> animations;
public:
	AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet);
	virtual ~AnimationComponent();

	void addAnimation(const std::string key, float speed, 
		int startFrameX, int startFrameY, int framesX, int framesY, int width, int height);
	void play(const std::string key, const float& dt);
};

