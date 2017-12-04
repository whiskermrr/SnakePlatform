#pragma once
#include "state.h"
#include "ConfigManager.h"
#include "ConsoleMenu.h"
#include "gameState.h"

class ConsoleOptionsMenu : public State
{
public:

	ConsoleOptionsMenu(ConfigManager* configManager, WINDOW* window, unsigned int width, unsigned int height, 
		unsigned int startWindowX, unsigned int startWindowY);
	void Initiate();
	void Update();
	void Render();
	void Destroy();
	void saveSettings();
	void setTextStrings();
	~ConsoleOptionsMenu();

public:
	WINDOW* window;
	ConfigManager* configManager;

	std::string choices[5] = { "Difficulty: ", "Teleports: ", "Music: ", "SoundFX: ", "Back" };
	std::string settings[5] = { "Normal", "ON", "ON", "ON", "" };
	int highlight = 0;
	int choice;

	unsigned int width;
	unsigned int height;
	unsigned int startWindowX;
	unsigned int startWindowY;
};

extern bool isMusicOn;
extern bool isSoundFxOn;
extern bool isTeleportsOn;
extern gameState mainState;

