#pragma once
#include "state.h"
#include "gameState.h"
#include "MainMenu.h"
#include <string>

class OptionsMenu : public State
{
public:
	OptionsMenu(sf::RenderWindow* window, ConfigManager* configManager);
	void Initiate();
	void Update();
	void Render();
	void Destroy();
	void getInput();
	void setTextColorsWhite();
	void setTextStrings();
	void updateMenuFunctionalityAndSetProperColors();
	void saveSettings();

private:
	sf::Font font;
	sf::Text tDifficulty;
	sf::Text tTeleports;
	sf::Text tMusic;
	sf::Text tSoundFX;
	sf::Text tBack;
	sf::Clock clock;

	int textSize = 30;
	int selected = 1;
	bool upKey = false;
	bool downKey = true;

	ConfigManager* configManager;
	sf::RenderWindow* window;
};

extern bool isMusicOn;
extern bool isSoundFxOn;
extern bool isTeleportsOn;
extern gameState mainState;
extern float KEY_FPS;

