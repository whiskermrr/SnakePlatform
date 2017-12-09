#include "ConsoleMenu.h"



ConsoleMenu::ConsoleMenu(unsigned int width, unsigned int height)
{
	initscr();
	clear();
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

	this->databaseHandler = new DatabaseHandler();
	databaseHandler->setFileName("config/db.txt");

	std::fstream file("resources/snak3_logo_2.txt");
	rows = 0;
	std::string buffer = "";

	if (!file.good())
	{
		file.close();
		std::cout << "ERROR!";
		Sleep(1000);
		mainState.setState(new ConsoleMenu(width / 2, height));
	}

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		buffer += line;
		rows++;
	}

	columns = buffer.size() / rows;

	logo = new char[buffer.size() + 1];
	strcpy(logo, buffer.c_str());

	RenderLogo();
	RenderScoreTable();
}

void ConsoleMenu::Update()
{
	choice = wgetch(window);

	switch (choice)
	{
	case 119:
		if (highlight != 0)
			highlight--;
		break;

	case 115:
		if (highlight != 2)
			highlight++;
		break;

	case 10:
		switch (highlight)
		{
		case 0:
			mainState.setState(new consoleGame(window, databaseHandler, width, height, startWindowX, startWindowY));
			break;

		case 1:
			mainState.setState(new ConsoleOptionsMenu(configManager, window, width, height, startWindowX, rows + 1));
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
			mvwprintw(window, i + 2 + rows, 1, choices[i].c_str());
			wattroff(window, A_REVERSE);
		}
		else
			mvwprintw(window, i + 2 + rows, 1, choices[i].c_str());
	}

	wrefresh(window);
}

void ConsoleMenu::RenderScoreTable()
{
	std::vector<std::string> records = databaseHandler->getDataFromDatabase();

	std::string name =			"Name        ";
	std::string score =			"Score       ";
	std::string difficulty =	"Difficulty  ";
	std::string teleports =		"Teleports";

	int space = name.size();

	mvwprintw(window, height / 2 - 2, width / 3, (name + score + difficulty + teleports).c_str());

	for (int i = 0; i < records.size(); i++)
	{
		std::vector<std::string> tokens;
		std::istringstream iss(records.at(i));
		std::copy(std::istream_iterator<std::string>(iss),
			std::istream_iterator<std::string>(),
			back_inserter(tokens));

		for (int j = 0; j < tokens.size(); j++)
		{
			mvwprintw(window, height / 2 + i, width / 3 + j * space, tokens.at(j).c_str());
		}
	}

	wrefresh(window);
}

void ConsoleMenu::RenderLogo()
{
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < columns; j++)
		{
			mvwaddch(window, i + 1, j + 1, logo[i * columns + j]);
			mvwaddch(window, rows + 1, j + 1, ' ');
		}
	}
}

void ConsoleMenu::Destroy()
{
	//delete[] logo;
}


ConsoleMenu::~ConsoleMenu()
{
}
