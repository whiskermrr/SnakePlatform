#include "consoleGame.h"



consoleGame::consoleGame(WINDOW* window, DatabaseHandler* databaseHandler, unsigned int width,
	unsigned int height, unsigned int startWindowX, unsigned int startWindowY)
{
	this->window = window;
	this->databaseHandler = databaseHandler;
	this->width = width;
	this->startWindowX = startWindowX;
	this->startWindowY = startWindowY;
	this->height = height;
	wclear(window);
	wrefresh(window);
	srand(time(NULL));

	
}

void consoleGame::Initiate()
{
	nickname = "none";
	getNickname();
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
		snake->incrementSnakeSize(5 * globalDifficulty);
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
	delete databaseHandler;
	databaseHandler = NULL;
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

void consoleGame::getNickname()
{
	nodelay(window, true);
	std::string tmpNickname = "";
	std::string line = "Nickname: ";
	mvwprintw(window, height / 2, width / 2 - line.size(), line.c_str());
	wrefresh(window);

	char c = getch();
	tmpNickname += c;

	while (c != 10)
	{
		mvwprintw(window, height / 2, width / 2 + line.size(), tmpNickname.c_str());
		wrefresh(window);
		c = getch();
		if(c != '\n')
			tmpNickname += c;
	}

	nickname = tmpNickname;
	wclear(window);
	nodelay(window, true);
	wrefresh(window);
}

void consoleGame::showGameOver()
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	std::string sOver = "GAME OVER!";

	wattron(window, COLOR_PAIR(1));
	mvwprintw(window, height / 2, width / 2 - sOver.size() / 2, sOver.c_str());
	wattroff(window, COLOR_PAIR(1));
	wrefresh(window);
	Sleep(1000);
	flushinp();
	halfdelay(100);
	if (!databaseHandler->addRecordToDatabase(nickname, globalDifficulty, isTeleportsOn, snake->getScores()))
	{
		std::string error = "Error saving scores to database.";
		wclear(window);
		mvwprintw(window, height / 2, width / 2 - error.size() / 2, error.c_str());
	}
	getch();
	
	endwin();
	mainState.setState(new ConsoleMenu(width / 2, height));
}

consoleGame::~consoleGame()
{
}
