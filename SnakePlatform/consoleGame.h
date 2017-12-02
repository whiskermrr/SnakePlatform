#pragma once
#include "state.h"
#include "SnakeConsole.h"
#include "ConsoleMap.h"


class consoleGame : public State
{
public:
	consoleGame(unsigned int width, unsigned int height);
	void Initiate();
	void Update();
	void Render();
	void Destroy();
	void Reset();
	~consoleGame();

public:
	SnakeConsole* snake;
	WINDOW* window;
	ConsoleMap map;
	unsigned int width;
	unsigned int height;
};

