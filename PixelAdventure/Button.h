#pragma once
#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button
{
private:
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	sf::Color textIdleColor;
	sf::Color textHoverColor;
	sf::Color textActiveColor;

	void initColors(std::string style);

public:
	Button(float x, float y, float width, float height, sf::Font* font, std::string text, unsigned fontSize, std::string style);
	~Button();

	const bool isActive() const;
	void update(const sf::Vector2f mousePosition);
	void render(sf::RenderTarget* target);
};

