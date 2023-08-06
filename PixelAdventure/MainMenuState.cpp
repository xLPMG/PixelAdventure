#include "MainMenuState.h"

void MainMenuState::initVariables()
{
}

void MainMenuState::initBackground()
{
	float windowWidth = static_cast<float>(window->getSize().x);
	float windowHeight = static_cast<float>(window->getSize().y);
	background.setSize(sf::Vector2f(windowWidth, windowHeight));
	if (!backgroundTexture.loadFromFile("Resources/Images/Background/bg1.png")) throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	float imgWidth = backgroundTexture.getSize().x;
	float imgHeight = backgroundTexture.getSize().y;
	float ratio = 1;
	if (imgWidth > windowWidth)
	{
		ratio = imgHeight / imgWidth;
		imgWidth = windowWidth;
		imgHeight = imgWidth * ratio;
	}
	int x = backgroundTexture.getSize().x / 2 - imgWidth / 2;
	int y = 0.2 * backgroundTexture.getSize().y;
	background.setSize(sf::Vector2f(imgWidth, imgHeight));
	background.setTexture(&backgroundTexture);
	background.setPosition(0,-0.15* imgHeight);
}

void MainMenuState::initFonts()
{
	if (!font.loadFromFile("Fonts/slkscr.ttf")) {
		throw("Error in MainMenuState: Could not load font");
	}
}

void MainMenuState::initKeybinds()
{
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");
	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";
		while (ifs >> key >> key2) {
			keybinds[key] = supportedKeys->at(key2);
		}
	}
	ifs.close();
}

void MainMenuState::initElements()
{
	int windowWidth = window->getSize().x;
	int windowHeight = window->getSize().y;
	int btnWidth = 250;
	int btnHeight = 60;
	int space = 25;

	int y1 = 0.5 * windowHeight;
	int y2 = y1 + (btnHeight + space) * 1;
	int y3 = y1 + (btnHeight + space) * 2;
	int x = windowWidth / 2 - btnWidth / 2;
	buttons["PLAY_BTN"] = new Button(x, y1, btnWidth, btnHeight, &font, "Play", 36);
	buttons["SETTINGS_BTN"] = new Button(x, y2, btnWidth, btnHeight, &font, "Settings", 36);
	buttons["EXIT_BTN"] = new Button(x, y3, btnWidth, btnHeight, &font, "Quit", 36);
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	initVariables();
	initBackground();
	initFonts();
	initKeybinds();
	initElements();
}
MainMenuState::~MainMenuState() {
	for (auto& it : buttons) {
		delete it.second;
	}
}

void MainMenuState::updateInput(const float& dt)
{

}
void MainMenuState::updateButtons()
{
	for (auto& it : buttons) {
		it.second->update(mousePosView);
	}

	if (buttons["PLAY_BTN"]->isActive()) {
		states->push(new GameState(window, supportedKeys, states));
	}
	if (buttons["EXIT_BTN"]->isActive()) {
		endState();
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
	for (auto& it : buttons) {
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target) target = this->window;
	target->draw(background);
	renderButtons(target);

	sf::Text title;
	title.setString("Pixel Adventure");
	title.setFont(font);
	title.setCharacterSize(90);
	int titleWidth = title.getGlobalBounds().width;
	int x = window->getSize().x / 2 - titleWidth / 2;
	title.setPosition(x, 45);
	target->draw(title);

	sf::Text mouseText;
	mouseText.setPosition(mousePosView.x+16, mousePosView.y);
	mouseText.setFont(font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << mousePosView.x << " " << mousePosView.y;
	mouseText.setString(ss.str());
	target->draw(mouseText);
}
