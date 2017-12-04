#pragma once
#include <curses.h>
#include "state.h"
#include "ConfigManager.h"
#include "consoleGame.h"
#include "gameState.h"
#include "ConsoleOptionsMenu.h"


class ConsoleMenu : public State
{
public:
	ConsoleMenu(unsigned int width, unsigned int height);
	void Initiate();
	void Update();
	void Render();
	void Destroy();
	~ConsoleMenu();

public:
	WINDOW* window;
	ConfigManager* configManager;

	std::string choices[3] = { "Play", "Options", "Exit" };
	int highlight = 0;
	int choice;

	unsigned int width;
	unsigned int height;
	unsigned int startWindowX = 20;
	unsigned int startWindowY = 5;
	
};
extern gameState mainState;
extern bool gameOver;

