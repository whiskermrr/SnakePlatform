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
	void Update();
	virtual void getInput();
	void incrementSnakeSize();
	void checkCollisionWithBorders();
	void checkCollisionWithItself();
	void setIsOnPill(bool isOnPill);
	bool isOnPill();
	void updateBody();
	~SnakeBase();

public:
	int direction;
	snakeBody body[100];
	int snakeSize;

	bool pause = false;
	bool _isOnPill = false;
};

extern bool gameOver;
extern int scores;
extern int blockSize;
extern int N;
extern int M;
extern bool isTeleportsOn;

