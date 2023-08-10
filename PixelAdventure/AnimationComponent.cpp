#include "AnimationComponent.h"
#include <iostream>

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet) :
	sprite(sprite), textureSheet(textureSheet)
{
}

AnimationComponent::~AnimationComponent()
{
	for (auto& i : animations) {
		delete i.second;
	}
}

void AnimationComponent::addAnimation(const std::string key, float speed, int startFrameX, int startFrameY, int framesX, int framesY, int width, int height)
{
	animations[key] = new Animation(sprite, textureSheet, speed, startFrameX, startFrameY, framesX, framesY, width, height);
}

void AnimationComponent::play(const std::string key, const float& dt)
{
	animations[key]->play(dt);
}

AnimationComponent::Animation::Animation(sf::Sprite& sprite, sf::Texture& textureSheet, float speed, int startFrameX, int startFrameY, int framesX, int framesY, int width, int height) :
	sprite(sprite), textureSheet(textureSheet), speed(speed), width(width), height(height) {
	timer = 0.f;
	startRect = sf::IntRect(startFrameX*width, startFrameY*height, width, height);
	currentRect = startRect;
	endRect = sf::IntRect(framesX * width, framesY*height, width, height);
	sprite.setTexture(textureSheet, true);
	sprite.setTextureRect(startRect);
};

void AnimationComponent::Animation::play(const float& dt)
{
	timer += 100.f * dt;
	if (timer >= speed) {
		timer = 0.f;
		if (currentRect != endRect) {
			currentRect.left += width;
		}
		else {
			currentRect.left = startRect.left;
		}
		sprite.setTextureRect(currentRect);
	}
}

void AnimationComponent::Animation::reset()
{
	timer = 0.f;
	currentRect = startRect;
}
