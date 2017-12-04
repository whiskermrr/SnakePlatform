#include "SnakeConsole.h"



SnakeConsole::SnakeConsole(WINDOW* window, unsigned int width, unsigned int height) : SnakeBase(width, height)
{
	this->window = window;
	texture = 'x';
}

void SnakeConsole::Update()
{
	checkCollisionWithBorders();
	updateBody();
	checkCollisionWithItself();
}


void SnakeConsole::updateBody()
{
	mvwaddch(window, body[snakeSize].y, body[snakeSize].x, ' ');
	mvwaddch(window, body[snakeSize].y - 1, body[snakeSize].x, ' ');
	SnakeBase::updateBody();
}

void SnakeConsole::Render()
{
	for (int i = 0; i <= snakeSize; i++)
		mvwaddch(window, body[i].y, body[i].x, texture);

	wrefresh(window);
}

void SnakeConsole::getInput()
{
	int key = wgetch(window);

	if (key == 119 && direction != DOWN)		direction = UP;
	else if (key == 115 && direction != UP)		direction = DOWN;
	else if (key == 97 && direction != RIGHT)	direction = LEFT;
	else if (key == 100 && direction != LEFT)	direction = RIGHT;
}

SnakeConsole::~SnakeConsole()
{
}
