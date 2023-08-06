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

void GameState::initTextures()
{
	if (!textures["PLAYER_IDLE_0"].loadFromFile("Resources/Images/Sprites/sorcerer.png")) throw "ERROR::GAME_STATE::COULD_NOT_LOAD_TEXTURE";
}

void GameState::initPlayers()
{
	player = new Player(0,0, textures["PLAYER_IDLE_0"]);
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys,states)
{
	initKeybinds();
	initTextures();
	initPlayers();
}
GameState::~GameState() {
	delete player;
}

void GameState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_LEFT")))) {
		player->move(dt, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_RIGHT")))) {
		player->move(dt, 1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_UP")))) {
		player->move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_DOWN")))) {
		player->move(dt, 0.f, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("CLOSE")))) {
		endState();
	}
}
void GameState::update(const float& dt)
{
	updateMousePosition();
	updateInput(dt);
	player->update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target) target = this->window;
	player->render(target);
}
