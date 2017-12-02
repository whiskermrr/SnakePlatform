#include "ConsoleMap.h"



ConsoleMap::ConsoleMap()
{
}


void ConsoleMap::Render(WINDOW* window, unsigned int width, unsigned int height, unsigned int startWindowX, unsigned int startWindowY)
{
	for (int i = startWindowY - 1; i <= height + startWindowY; i++)
	{
		mvprintw(i, startWindowX - 1, "#");
		mvprintw(i, startWindowX + width, "#");
	}

	for (int i = startWindowX - 1; i <= width + startWindowX; i++)
	{
		mvprintw(startWindowY - 1, i, "#");
		mvprintw(startWindowY + height, i, "#");
	}

	refresh();
}

ConsoleMap::~ConsoleMap()
{
}
