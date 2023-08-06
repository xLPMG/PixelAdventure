#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states){
	this->window = window;
	this->supportedKeys = supportedKeys;
	this->states = states;
	shouldEnd = false;
}
State::~State(){}

const bool& State::getQuit() const
{
	return shouldEnd;
}

void State::endState()
{
	shouldEnd = true;
}

void State::updateInput(const float& dt)
{
}

void State::updateMousePosition()
{
	mousePosScreen = sf::Mouse::getPosition();
	mousePosWindow = sf::Mouse::getPosition(*this->window);
	mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
