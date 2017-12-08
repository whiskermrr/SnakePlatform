#include "ConsoleOptionsMenu.h"


ConsoleOptionsMenu::ConsoleOptionsMenu(ConfigManager* configManager, WINDOW* window, unsigned int width, unsigned int height,
	unsigned int startWindowX, unsigned int startWindowY)
{
	this->window = window;
	this->configManager = configManager;
	this->width = width;
	this->height = height;
	this->startWindowX = startWindowX;
	this->startWindowY = startWindowY;
}

void ConsoleOptionsMenu::Initiate()
{
	box(window, 0, 0);
}

void ConsoleOptionsMenu::Update()
{
	choice = wgetch(window);

	switch (choice)
	{
	case 119:
		if (highlight != 0)
			highlight--;
		break;

	case 115:
		if (highlight != 4)
			highlight++;
		break;

	case 10:
		if (highlight == 4)
		{
			mainState.setState(new ConsoleMenu(width / 2, height));
		}
		break;

	case 100:
	case 97:
		switch (highlight)
		{
		case 0:
			if(choice == 97 && globalDifficulty != 1)			globalDifficulty--;
			else if (choice == 100 && globalDifficulty != 3)	globalDifficulty++;
			break;

		case 1:
			(isTeleportsOn ? isTeleportsOn = false : isTeleportsOn = true);
			break;

		case 2:
			(isMusicOn ? isMusicOn = false : isMusicOn = true);
			break;

		case 3:
			(isSoundFxOn ? isSoundFxOn = false : isSoundFxOn = true);
			break;

		default:
			break;
		}
	}
}

void ConsoleOptionsMenu::Render()
{
	settings[1] = isTeleportsOn ? "ON" : "OFF";
	settings[2] = isMusicOn ? "ON" : "OFF";
	settings[3] = isSoundFxOn ? "ON" : "OFF";
	settings[0] = "";

	switch (globalDifficulty)
	{
	case 1:
		settings[0] = "EASY";
		break;
	case 2:
		settings[0] = "NORMAL";
		break;
	case 3:
		settings[0] = "HARD";
		break;
	}

	for (int i = 0; i < 5; i++)
	{
		mvwprintw(window, i + 1 + startWindowY, 1, "                      ");

		if (i == highlight)
		{
			wattron(window, A_REVERSE);
			mvwprintw(window, i + 1 + startWindowY, 1, (choices[i] + settings[i]).c_str());
			wattroff(window, A_REVERSE);
		}
		else
			mvwprintw(window, i + 1 + startWindowY, 1, (choices[i] + settings[i]).c_str());
	}

	wrefresh(window);
}

void ConsoleOptionsMenu::saveSettings()
{
	if (!configManager->saveConfig())
		std::cout << "ERROR!" << std::endl;
}

void ConsoleOptionsMenu::Destroy()
{
	saveSettings();
}


ConsoleOptionsMenu::~ConsoleOptionsMenu()
{
}
