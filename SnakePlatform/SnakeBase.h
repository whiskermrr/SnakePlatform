#pragma once
#include <stdlib.h>

enum directions
{
	RIGHT, DOWN, LEFT, UP
};

struct snakeBody
{
	int x;
	int y;
};

class SnakeBase
{
public:
	SnakeBase();
	SnakeBase(unsigned int width, unsigned int height);
	void Update();
	virtual void getInput();
	void incrementSnakeSize(int incrementer);
	void checkCollisionWithBorders();
	void checkCollisionWithItself();
	void setIsOnPill(bool isOnPill);
	bool isOnPill();
	bool isDead();
	void setIsDead(bool dead);
	void setScores(int scores);
	int getScores();
	void updateBody();
	~SnakeBase();

public:
	int direction;
	snakeBody body[400];
	int snakeSize;

	unsigned int width;
	unsigned int height;
	unsigned int scores;

	bool pause = false;
	bool _isOnPill = false;
	bool _isDead = false;
};


extern bool isTeleportsOn;

