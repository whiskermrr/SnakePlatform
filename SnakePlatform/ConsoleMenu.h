#pragma once
#include <curses.h>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include "state.h"
#include "ConfigManager.h"
#include "consoleGame.h"
#include "gameState.h"
#include "ConsoleOptionsMenu.h"
#include "DatabaseHandler.h"


class ConsoleMenu : public State
{
public:
	ConsoleMenu(unsigned int width, unsigned int height);
	void Initiate();
	void Update();
	void Render();
	void Destroy();
	void RenderLogo();
	void RenderScoreTable();
	~ConsoleMenu();

public:
	WINDOW* window;
	ConfigManager* configManager;
	DatabaseHandler* databaseHandler;

	std::string choices[3] = { "Play", "Options", "Exit" };
	int highlight = 0;
	int choice;

	unsigned int width;
	unsigned int height;
	unsigned int startWindowX = 20;
	unsigned int startWindowY = 5;
	char* logo;
	unsigned int rows;
	unsigned int columns;
	
};
extern gameState mainState;
extern bool gameOver;

