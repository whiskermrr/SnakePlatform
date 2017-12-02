#include "ConsoleMap.h"



ConsoleMap::ConsoleMap()
{
}


void ConsoleMap::Render(WINDOW* window, unsigned int width, unsigned int height, unsigned int startWindowX, unsigned int startWindowY)
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);

	attron(COLOR_PAIR(1));

	for (int i = startWindowY - 1; i <= height + startWindowY; i++)
	{
		mvaddch(i, startWindowX - 1, textureBorder | A_ALTCHARSET);
		mvaddch(i, startWindowX + width, textureBorder | A_ALTCHARSET);
	}

	for (int i = startWindowX - 1; i <= width + startWindowX; i++)
	{
		mvaddch(startWindowY - 1, i, textureBorder | A_ALTCHARSET);
		mvaddch(startWindowY + height, i, textureBorder | A_ALTCHARSET);
	}

	attroff(COLOR_PAIR(1));

	refresh();
}

ConsoleMap::~ConsoleMap()
{
}
