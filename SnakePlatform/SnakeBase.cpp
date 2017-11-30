#include "SnakeBase.h"


SnakeBase::SnakeBase()
{
	snakeSize = 3;
	direction = DOWN;

	for (int i = 0; i <= snakeSize; i++)
	{
		body[i].x = 10;
		body[i].y = 10 - i;
	}
}

void SnakeBase::getInput()
{

}

void SnakeBase::Update()
{
	checkCollisionWithBorders();
	updateBody();
	checkCollisionWithItself();
}

void SnakeBase::checkCollisionWithItself()
{
	for (int i = 2; i <= snakeSize; i++)
	{
		if (body[0].x == body[i].x && body[0].y == body[i].y)
			gameOver = true;
	}
}

void SnakeBase::checkCollisionWithBorders()
{
	if (body[0].x <= 0 && direction == LEFT)
		body[0].x = N;
	else if (body[0].x >= N - 1 && direction == RIGHT)
		body[0].x = -1;
	else if (body[0].y <= 0 && direction == UP)
		body[0].y = M;
	else if (body[0].y >= M - 1 && direction == DOWN)
		body[0].y = -1;
}

void SnakeBase::updateBody()
{
	if (direction == RIGHT) body[0].x += 1;
	if (direction == DOWN) body[0].y += 1;
	if (direction == LEFT) body[0].x -= 1;
	if (direction == UP) body[0].y -= 1;

	for (int i = snakeSize; i > 0; i--)
	{
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}
}

void SnakeBase::incrementSnakeSize()
{
	snakeSize += 1;
}

void SnakeBase::setIsOnPill(bool isOnPill)
{
	_isOnPill = isOnPill;
}

bool SnakeBase::isOnPill()
{
	return _isOnPill;
}



SnakeBase::~SnakeBase()
{
}
