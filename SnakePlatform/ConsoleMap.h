#pragma once
#include <curses.h>


class ConsoleMap
{
public:
	ConsoleMap();
	void Render(WINDOW* window, unsigned int width, unsigned int height, unsigned int startWindowX, unsigned int startWindowY);
	~ConsoleMap();
};

