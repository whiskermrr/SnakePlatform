#include "consoleGame.h"



consoleGame::consoleGame(unsigned int width, unsigned int height)
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	halfdelay(1);

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
	refresh();
	wrefresh(window);
	srand(time(NULL));
}

void consoleGame::Initiate()
{
	snake = new SnakeConsole(window, width, height);
	map.Render(window, width, height, startWindowX, startWindowY);
	setRandomPositionOfFood();
	printScores();
}

void consoleGame::Update()
{
	snake->getInput();
	snake->Update();

	if (snake->body[0].x == food.x && snake->body[0].y == food.y)
	{
		snake->incrementSnakeSize();
		snake->scores++;
		setRandomPositionOfFood();
		printScores();
	}

	if (snake->isDead())
		gameOver = true;
}

void consoleGame::Render()
{
	snake->Render();
	mvwaddch(window, food.y, food.x, textureFood);
}

void consoleGame::Destroy()
{
	delete snake;
	snake = NULL;
	//delwin(window);
	endwin();
}

void consoleGame::Reset()
{

}

void consoleGame::setRandomPositionOfFood()
{
	food.x = rand() % width;
	food.y = rand() % height;
}

void consoleGame::printScores()
{
	std::string scores = "Total Score: " + std::to_string(snake->getScores());
	mvprintw(startWindowY - 3, startWindowX, scores.c_str());
	refresh();
}

consoleGame::~consoleGame()
{
}
