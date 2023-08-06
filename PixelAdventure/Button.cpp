#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text, unsigned fontSize, std::string style)
{
	buttonState = BTN_IDLE;
	initColors(style);

	shape.setSize(sf::Vector2f(width,height));
	shape.setPosition(sf::Vector2f(x,y));
	shape.setFillColor(idleColor);

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(fontSize);
	this->text.setPosition(
		shape.getPosition().x + (shape.getGlobalBounds().width - this->text.getGlobalBounds().width) / 2.0f,
		(shape.getPosition().y + (shape.getGlobalBounds().height - this->text.getGlobalBounds().height) / 2.0f)-this->text.getGlobalBounds().height/2.0f
	);
}

Button::~Button()
{

}

const bool Button::isActive() const
{
	if (buttonState == BTN_ACTIVE) return true;
	return false;
}

void Button::update(const sf::Vector2f mousePosition)
{
	buttonState = BTN_IDLE;
	shape.setFillColor(idleColor);
	text.setFillColor(textIdleColor);
	if (this->shape.getGlobalBounds().contains(mousePosition)) {
		buttonState = BTN_HOVER;
		shape.setFillColor(hoverColor);
		text.setFillColor(textHoverColor);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			buttonState = BTN_ACTIVE;
			shape.setFillColor(activeColor);
			text.setFillColor(textActiveColor);
		}
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(shape);
	target->draw(text);
}

void Button::initColors(std::string style)
{
	if (style == "mainmenu") {
		idleColor = sf::Color(0, 0, 0, 0);
		hoverColor = sf::Color(0, 0, 0, 0);
		activeColor = sf::Color(0, 0, 0, 0);
		textIdleColor = sf::Color(120, 120, 120, 200);
		textHoverColor = sf::Color(200, 200, 200, 200);
		textActiveColor = sf::Color(255, 255, 255, 255);
	}
	else {
		idleColor = sf::Color(77, 62, 48, 255);
		hoverColor = sf::Color(133, 107, 82, 255);
		activeColor = sf::Color(166, 136, 108, 255);
		textIdleColor = sf::Color(255, 255, 255, 255);
		textHoverColor = sf::Color(255, 255, 255, 255);
		textActiveColor = sf::Color(255, 255, 255, 255);
	}
}
