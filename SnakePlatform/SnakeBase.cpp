#include "SnakeBase.h"


SnakeBase::SnakeBase()
{
}

SnakeBase::SnakeBase(unsigned int width, unsigned int height)
{
	snakeSize = 5;
	direction = DOWN;
	this->scores = 0;
	this->width = width;
	this->height = height;

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
			_isDead = true;
	}
}

void SnakeBase::checkCollisionWithBorders()
{
	if (body[0].x <= 0 && direction == LEFT)
		body[0].x = width;
	else if (body[0].x >= width - 1 && direction == RIGHT)
		body[0].x = -1;
	else if (body[0].y <= 0 && direction == UP)
		body[0].y = height;
	else if (body[0].y >= height - 1 && direction == DOWN)
		body[0].y = -1;
}

void SnakeBase::updateBody()
{
	for (int i = snakeSize; i > 0; i--)
	{
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}

	if (direction == RIGHT) body[0].x += 1;
	if (direction == DOWN) body[0].y += 1;
	if (direction == LEFT) body[0].x -= 1;
	if (direction == UP) body[0].y -= 1;
}

void SnakeBase::incrementSnakeSize(int incrementer)
{
	snakeSize += incrementer;
}

void SnakeBase::setIsOnPill(bool isOnPill)
{
	_isOnPill = isOnPill;
}

bool SnakeBase::isOnPill()
{
	return _isOnPill;
}

void SnakeBase::setScores(int scores)
{
	this->scores = scores;
}

int SnakeBase::getScores()
{
	return this->scores;
}

void SnakeBase::setIsDead(bool dead)
{
	_isDead = dead;
}

bool SnakeBase::isDead()
{
	return _isDead;
}


SnakeBase::~SnakeBase()
{
}
