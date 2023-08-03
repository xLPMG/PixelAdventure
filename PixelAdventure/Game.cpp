#include "Game.h"
#include "MainMenuState.h"

#define WIN_WIDTH 1600
#define WIN_HEIGHT 900

void Game::init() {
	std::ifstream ifs("Config/window.ini");
	sf::VideoMode windowBounds(1600, 900);
	std::string title = "None";
	unsigned framerateLimit = 144;
	bool vsynchEnabled = false;
	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> windowBounds.width >> windowBounds.height;
		ifs >> framerateLimit;
		ifs >> vsynchEnabled;
	}
	ifs.close();

	window = new sf::RenderWindow(windowBounds, title);
	window->setFramerateLimit(framerateLimit);
	window->setVerticalSyncEnabled(vsynchEnabled);
	
	initKeys();
	states.push(new MainMenuState(window, &supportedKeys));
	run();
}

void Game::initKeys()
{
	std::ifstream ifs("Config/supported_keys.ini");
	if(ifs.is_open()){
		std::string key = "";
		int val = 0;
		while (ifs >> key >> val) {
			supportedKeys[key] = val;
		}
	}
	ifs.close();
}

void Game::pollEvents() {
	while (window->pollEvent(event))
	{
		switch (event.type) {
		case sf::Event::Closed:
			window->close();
			break;
		}
	}
}

void Game::updateDt() {
	dt = dtClock.restart().asSeconds();
}
void Game::update() {
	pollEvents();
	if (!states.empty()) {
		states.top()->update(dt);
		if(states.top()->getQuit()){
			states.top()->endState();
			delete states.top();
			states.pop();
		}
	}
	else {
		window->close();
	}
}
void Game::render() {
	window->clear();
	//draw
	if(!states.empty()) {
		states.top()->render();
	}
	//end draw
	window->display();
}

Game::Game() {
	init();
}
Game::~Game() {
	delete window;
	while(!states.empty()){
		delete states.top();
		states.pop();
	}
}
void::Game::run() {
	while (window->isOpen())
	{
		updateDt();
		update();
		render();
	}
}
