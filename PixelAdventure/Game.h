#pragma once
#include "GameState.h"

class Game
{
private:
	sf::RenderWindow *window;
	sf::Event event;
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	void init();
	void pollEvents();
	void updateDt();
	void update();
	void render();
public:
	Game();
	virtual ~Game();
	void run();
};

