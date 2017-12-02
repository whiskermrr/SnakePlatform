#include "ConsoleMap.h"



ConsoleMap::ConsoleMap()
{
}


void ConsoleMap::Render(WINDOW* window, unsigned int width, unsigned int height, unsigned int startWindowX, unsigned int startWindowY)
{
	for (int i = startWindowY - 1; i <= height + startWindowY; i++)
	{
		mvaddch(i, startWindowX - 1, textureBorder);
		mvaddch(i, startWindowX + width, textureBorder);
	}

	for (int i = startWindowX - 1; i <= width + startWindowX; i++)
	{
		mvaddch(startWindowY - 1, i, textureBorder);
		mvaddch(startWindowY + height, i, textureBorder);
	}

	refresh();
}

ConsoleMap::~ConsoleMap()
{
}
