#pragma once
#include "state.h"
#include "gameState.h"
#include "MainMenu.h"
#include <string>

class OptionsMenu : public State
{
public:
	OptionsMenu();
	void Initiate(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
	void getInput();
	void setTextColorsWhite();
	void setTextStrings();
	void updateMenuFunctionalityAndSetProperColors();

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
	int selectedDifficulty = 2;
	int selectedMusic = 1;
	int selectedSoundFX = 1;
	bool upKey = false;
	bool downKey = true;
	float KEY_FPS = 8.0f;
};

extern bool isMusicOn;
extern bool isSoundFxOn;
extern bool isTeleportsOn;
extern gameState mainState;

