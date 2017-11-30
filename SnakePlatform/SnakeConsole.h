#pragma once
#include <stdlib.h>
#include <curses.h>
#include "SnakeBase.h"

class SnakeConsole : public SnakeBase
{
public:
	SnakeConsole(WINDOW * window);
	void getInput();
	void Render();
	void Update();
	void updateBody();
	~SnakeConsole();

public:
	WINDOW* window;
	char texture;
};

