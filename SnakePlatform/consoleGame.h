#pragma once
#include "state.h"
#include "SnakeConsole.h"


class consoleGame : public State
{
public:
	consoleGame();
	void Initiate();
	void Update();
	void Render();
	void Destroy();
	void Reset();
	~consoleGame();

public:
	SnakeConsole* snake;
	WINDOW* window;
};

extern int N;
extern int M;

