#include "consoleGame.h"



consoleGame::consoleGame(WINDOW* window, unsigned int width, unsigned int height, unsigned int startWindowX, unsigned int startWindowY)
{
	this->window = window;
	this->width = width;
	this->startWindowX = startWindowX;
	this->startWindowY = startWindowY;
	this->height = height;
	wclear(window);
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
	flushinp();
	snake->Update();

	if (snake->body[0].x == food.x && snake->body[0].y == food.y)
	{
		snake->incrementSnakeSize();
		snake->scores++;
		setRandomPositionOfFood();
		printScores();
	}

	if (snake->isDead())
	{
		showGameOver();
	}
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

void consoleGame::showGameOver()
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);

	std::string sOver = "GAME OVER!";
	wattron(window, COLOR_PAIR(1));
	mvwprintw(window, height / 2, width / 2 - sOver.size() / 2, sOver.c_str());
	wattroff(window, COLOR_PAIR(1));
	wrefresh(window);

	halfdelay(100);
	getch();
	endwin();
	mainState.setState(new ConsoleMenu(width / 2, height));
}

consoleGame::~consoleGame()
{
}
