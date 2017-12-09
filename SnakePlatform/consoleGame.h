#pragma once
#include <stdlib.h>
#include "state.h"
#include "SnakeConsole.h"
#include "ConsoleMap.h"
#include "ConsoleMenu.h"
#include "gameState.h"
#include "DatabaseHandler.h"


class consoleGame : public State
{
public:
	consoleGame(WINDOW* window, DatabaseHandler* databaseHandler, unsigned int width,
		unsigned int height, unsigned int startWindowX, unsigned int startWindowY);
	void Initiate();
	void Update();
	void Render();
	void Destroy();
	void Reset();
	void setRandomPositionOfFood();
	void printScores();
	void showGameOver();
	void getNickname();
	~consoleGame();

public:
	SnakeConsole* snake;
	WINDOW* window;
	DatabaseHandler* databaseHandler;
	ConsoleMap map;
	snakeBody food;
	unsigned int width;
	unsigned int height;
	unsigned int startWindowX;
	unsigned int startWindowY;
	char textureFood = '@';
	std::string nickname;
};

extern gameState mainState;
extern bool isTeleportsOn;
extern int globalDifficulty;
extern bool gameOver;

