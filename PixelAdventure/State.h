#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<stack>
#include<map>

#include "Entity.h"

class State
{
private:
	bool shouldEnd;
protected:
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;

	std::vector<sf::Texture> textures;
	virtual void initKeybinds()=0;
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~State();

	const bool& getQuit() const;
	virtual void checkEnded();
	virtual void endState() = 0;
	virtual void updateInput(const float& dt)=0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr)=0;
};

