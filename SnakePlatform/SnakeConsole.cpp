#include "SnakeConsole.h"



SnakeConsole::SnakeConsole(WINDOW* window)
{
	this->window = window;
	snakeSize = 3;
	direction = DOWN;
	texture = 'x';

	for (int i = 0; i <= snakeSize; i++)
	{
		body[i].x = 10;
		body[i].y = 10 - i;
	}
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
	else if (key == 115 && direction != UP)	direction = DOWN;
	else if (key == 97 && direction != RIGHT)	direction = LEFT;
	else if (key == 100 && direction != LEFT)	direction = RIGHT;
}

SnakeConsole::~SnakeConsole()
{
}
