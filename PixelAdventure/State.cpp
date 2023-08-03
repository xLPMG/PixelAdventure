#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys){
	this->window = window;
	this->supportedKeys = supportedKeys;
	shouldEnd = false;
}
State::~State(){}

const bool& State::getQuit() const
{
	return shouldEnd;
}

void State::checkEnded()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("CLOSE")))) {
		shouldEnd=true;
	}
}
