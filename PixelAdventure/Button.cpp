#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text, int fontSize)
{
	buttonState = BTN_IDLE;

	shape.setSize(sf::Vector2f(width,height));
	shape.setPosition(sf::Vector2f(x,y));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(fontSize);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width - this->text.getGlobalBounds().width) / 2.0f,
		(this->shape.getPosition().y + (this->shape.getGlobalBounds().height - this->text.getGlobalBounds().height) / 2.0f)- this->text.getGlobalBounds().height/2.0f
	);

	idleColor = sf::Color(77, 62, 48, 255);
	hoverColor = sf::Color(133, 107, 82, 255);
	activeColor = sf::Color(166, 136, 108, 255);

	shape.setFillColor(idleColor);
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
	if (this->shape.getGlobalBounds().contains(mousePosition)) {
		buttonState = BTN_HOVER;
		shape.setFillColor(hoverColor);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			buttonState = BTN_ACTIVE;
			shape.setFillColor(activeColor);
		}
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(shape);
	target->draw(text);
}
