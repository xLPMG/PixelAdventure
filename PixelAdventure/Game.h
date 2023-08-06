#pragma once
#include "GameState.h"

class Game
{
private:
	sf::RenderWindow *window;
	sf::Event event;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;
	std::map<std::string, int> supportedKeys;

	void init();
	void initVariables();
	void initWindow();
	void initKeys();
	void initStates();
	void pollEvents();
	void updateDt();
	void update();
	void render();
public:
	Game();
	virtual ~Game();
	void run();
};

