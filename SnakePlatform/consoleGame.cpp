#include "consoleGame.h"



consoleGame::consoleGame()
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	halfdelay(1);

	window = newwin(30, 30, 0, 0);
	box(window, 0, 0);
	keypad(window, true);
	refresh();
	wrefresh(window);

	snake = new SnakeConsole(window);
}

void consoleGame::Initiate()
{

}

void consoleGame::Update()
{
	snake->getInput();
	snake->Update();
}

void consoleGame::Render()
{
	snake->Render();
}

void consoleGame::Destroy()
{
	delete snake;
	snake = NULL;
	delwin(window);
	endwin();
}

void consoleGame::Reset()
{

}

consoleGame::~consoleGame()
{
}
