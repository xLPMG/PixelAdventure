#include "Game.h"
#include "MainMenuState.h"

void Game::init() {
	initVariables();
	initWindow();
	initKeys();
	initStates();
	run();
}

void Game::initVariables()
{
	window = nullptr;
	fullscreen = false;
	dt = 0.f;
}

void Game::initWindow()
{
	std::ifstream ifs("Config/window.ini");
	videoModes = sf::VideoMode::getFullscreenModes();

	sf::VideoMode windowBounds = sf::VideoMode::getDesktopMode();
	std::string title = "None";

	bool fullscreen = false;
	unsigned framerateLimit = 144;
	bool vsynchEnabled = false;
	unsigned antialiasing_level = 0;

	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> windowBounds.width >> windowBounds.height;
		ifs >> fullscreen;
		ifs >> framerateLimit;
		ifs >> vsynchEnabled;
		ifs >> antialiasing_level;
	}
	ifs.close();

	this->fullscreen = fullscreen;
	windowSettings.antialiasingLevel = antialiasing_level;
	if (this->fullscreen)
		window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), title, sf::Style::Fullscreen, windowSettings);
	else window = new sf::RenderWindow(windowBounds, title, sf::Style::Titlebar | sf::Style::Close, windowSettings);
	window->setFramerateLimit(framerateLimit);
	window->setVerticalSyncEnabled(vsynchEnabled);
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

void Game::initStates()
{
	states.push(new MainMenuState(window, &supportedKeys, &states));
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
