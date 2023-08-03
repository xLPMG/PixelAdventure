#include "GameState.h"

void GameState::initKeybinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini");
	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";
		while (ifs >> key >> key2) {
			keybinds[key] = supportedKeys->at(key2);
		}
	}
	ifs.close();
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{
	initKeybinds();
}
GameState::~GameState() {}

void GameState::endState() {
	std::cout << "ending" << std::endl;
}

void GameState::updateInput(const float& dt)
{
	checkEnded();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_LEFT")))) {
		player.move(dt, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_RIGHT")))) {
		player.move(dt, 1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_UP")))) {
		player.move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_DOWN")))) {
		player.move(dt, 0.f, 1.f);
	}
}
void GameState::update(const float& dt)
{
	updateMousePosition();
	updateInput(dt);
	player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target) target = this->window;
	player.render(target);
}
