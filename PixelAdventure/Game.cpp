#include "Game.h"
#include <SFML\Graphics.hpp>

#define WIN_WIDTH 1600
#define WIN_HEIGHT 900

void Game::init() {
	this->window = new sf::RenderWindow(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "PixelAdventure");
	run();
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

Game::Game() {
	init();
}
Game::~Game(){
	delete window;
}
void Game::update() {
	pollEvents();
}
void Game::render() {
	window->clear();
	//draw
	//end draw
	window->display();
}

void::Game::run() {
	while (window->isOpen())
	{
		update();
		render();
	}
}
