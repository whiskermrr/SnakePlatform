#pragma once
#include "state.h"
#include "SnakeConsole.h"
#include "ConsoleMap.h"
#include <stdlib.h>


class consoleGame : public State
{
public:
	consoleGame(unsigned int width, unsigned int height);
	void Initiate();
	void Update();
	void Render();
	void Destroy();
	void Reset();
	void setRandomPositionOfFood();
	void printScores();
	void showGameOver();
	~consoleGame();

public:
	SnakeConsole* snake;
	WINDOW* window;
	ConsoleMap map;
	snakeBody food;
	unsigned int width;
	unsigned int height;
	unsigned int startWindowX = 20;
	unsigned int startWindowY = 5;
	char textureFood = '@';
};


extern bool gameOver;

