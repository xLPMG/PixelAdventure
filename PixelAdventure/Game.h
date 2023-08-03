#pragma once
#include <SFML\Graphics.hpp>

class Game
{
private:
	sf::RenderWindow *window;
	sf::Event event;

	void init();
	void pollEvents();
	void update();
	void render();
public:
	Game();
	virtual ~Game();
	void run();
};

