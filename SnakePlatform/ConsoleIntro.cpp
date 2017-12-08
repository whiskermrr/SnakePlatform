#include "ConsoleIntro.h"



ConsoleIntro::ConsoleIntro(unsigned int width, unsigned int height)
{
	this->width = width * 2;
	this->height = height;

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
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	srand(time(NULL));
}


void ConsoleIntro::Initiate()
{
	std::fstream file("resources/snak3_logo.txt");
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
}

void ConsoleIntro::Update()
{
	if (startWindowY != 5)
		startWindowY--;
}

void ConsoleIntro::Render()
{
	if (startWindowY != 5)
	{
		RenderLogo();
	}
	else if(!end)
	{
		SimulateTyping();
	}
	else if(counterFlicker > 0)
	{
		FlickerLogo();
		counterFlicker--;
	}
	else
	{
		mainState.setState(new ConsoleMenu(width / 2, height));
	}
		
	refresh();
}

void ConsoleIntro::RenderLogo()
{
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < columns; j++)
		{
			mvaddch(startWindowY + i, startWindowX + j, logo[i * columns + j]);
			mvaddch(startWindowY + rows, startWindowX + j, ' ');
		}
	}
}

void ConsoleIntro::FlickerLogo()
{
	attron(COLOR_PAIR(flicker));
	RenderLogo();
	attroff(COLOR_PAIR(flicker));

	if (++flicker == 4)	flicker = 1;
}

void ConsoleIntro::SimulateTyping()
{
	curs_set(1);
	std::string signature = "Created by ";
	std::string name = "Wiktor Wolski";
	std::string nick = "whiskermrr";
	for (int i = 0; i < signature.size(); i++)
	{
		mvaddch(startWindowX + height / 2, startWindowX + width / 2 + i, signature[i]);
		Sleep(rand() % 100 + 100);
		refresh();
	}

	for(int i = 0; i < name.size(); i++)
	{
		mvaddch(startWindowX + height / 2, startWindowX + width / 2 + i + signature.size(), name[i]);
		Sleep(rand() % 100 + 100);
		refresh();
	}

	Sleep(1000);

	for (int i = name.size() - 1; i >= 0; i--)
	{
		mvaddch(startWindowX + height / 2, startWindowX + width / 2 + i + signature.size(), ' ');
		Sleep(rand() % 50 + 50);
		refresh();
	}

	for (int i = 0; i < nick.size(); i++)
	{
		mvaddch(startWindowX + height / 2, startWindowX + width / 2 + i + signature.size(), nick[i]);
		Sleep(rand() % 100 + 100);
		refresh();
	}

	end = true;
	Sleep(2000);
	curs_set(0);
}

void ConsoleIntro::Destroy()
{
	delete[] logo;
	endwin();
}

ConsoleIntro::~ConsoleIntro()
{

}
