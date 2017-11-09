#pragma once
#include "state.h"
#include "gameState.h"
#include "ConfigManager.h"
#include "OptionsMenu.h"

class MainMenu : public State
{
public:
	MainMenu();
	void Initiate(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	sf::Font font;
	sf::Text tTitle;
	sf::Text tPlay;
	sf::Text tOptions;
	sf::Text tQuit;
	sf::Clock clock;

	int titleSize = 60;
	int textSize = 30;
	int selected = 1;
	bool upKey = false;
	bool downKey = true;

	ConfigManager* configManager;
};

extern gameState mainState;
extern bool gameExit;
extern float KEY_FPS;

