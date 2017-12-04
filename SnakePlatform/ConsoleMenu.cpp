#include "ConsoleMenu.h"



ConsoleMenu::ConsoleMenu(unsigned int width, unsigned int height)
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);

	if (!has_colors())
	{
		printw("Terminal does not support colours.");
		getch();
		gameOver = true;
	}

	start_color();

	this->width = width * 2;
	this->height = height;

	window = newwin(height, width * 2, startWindowY, startWindowX);
	keypad(window, true);
	nodelay(window, true);
	box(window, 0, 0);
	refresh();
	wrefresh(window);
}

void ConsoleMenu::Initiate()
{
	this->configManager = new ConfigManager();

	configManager->setFileName("config/config.cfg");
	configManager->loadConfigFile();
}

void ConsoleMenu::Update()
{
	choice = wgetch(window);

	switch (choice)
	{
	case 119:
		if (choice != 0)
			highlight--;
		break;

	case 115:
		if (choice != 2)
			highlight++;
		break;

	case 10:
		switch (highlight)
		{
		case 0:
			mainState.setState(new consoleGame(window, width, height, startWindowX, startWindowY));
			break;

		case 1:
			mainState.setState(new ConsoleOptionsMenu(configManager, window, width, height, startWindowX, startWindowY));
			break;

		case 2:
			gameOver = true;
			break;

		default:
			break;
		}

	default:
		break;
	}
}

void ConsoleMenu::Render()
{
	for (int i = 0; i < 3; i++)
	{
		if (i == highlight)
		{
			wattron(window, A_REVERSE);
			mvwprintw(window, i + 1, 1, choices[i].c_str());
			wattroff(window, A_REVERSE);
		}
		else
			mvwprintw(window, i + 1, 1, choices[i].c_str());
	}

	wrefresh(window);
}

void ConsoleMenu::Destroy()
{

}


ConsoleMenu::~ConsoleMenu()
{
}
