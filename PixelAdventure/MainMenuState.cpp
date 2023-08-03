#include "MainMenuState.h"

void MainMenuState::initFonts()
{
	if (!font.loadFromFile("Fonts/slkscr.ttf")) {
		throw("Error in MainMenuState: Could not load font");
	}
}

void MainMenuState::initKeybinds()
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

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{
	initFonts();
	initKeybinds();

	buttons["PLAY_BTN"] = new Button(100, 100, 250, 50, &font, "Play", 32);
	buttons["EXIT_BTN"] = new Button(100, 200, 250, 50, &font, "Quit", 32);

	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	background.setFillColor(sf::Color::Blue);
}
MainMenuState::~MainMenuState() {
	for (auto& it : buttons) {
		delete it.second;
	}
}

void MainMenuState::endState() {
	std::cout << "ending" << std::endl;
}

void MainMenuState::initFont()
{
}

void MainMenuState::updateInput(const float& dt)
{
	checkEnded();
}
void MainMenuState::updateButtons()
{
	for (auto& it : buttons) {
		it.second->update(mousePosView);
	}

	if (buttons["PLAY_BTN"]->isActive()) {
		states.push(new GameState(window, &supportedKeys));
	}
	if (buttons["EXIT_BTN"]->isActive()) {
		shouldEnd = true;
	}
}
void MainMenuState::update(const float& dt)
{
	updateMousePosition();
	updateInput(dt);
	updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto &it : buttons) {
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target) target = this->window;
	target->draw(background);
	renderButtons(target);
}
