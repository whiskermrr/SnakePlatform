#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
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

class Snake : public sf::Sprite
{
public:
	Snake();
	void Update();
	void getInput();
	void incrementSnakeSize();
	void Render(sf::RenderWindow* window);
	void checkCollisionWithBorders();
	void checkCollisionWithItself();
	void setIsOnPill(bool isOnPill);
	bool isOnPill();
	void updateBody();
	~Snake();

public:
	int direction;
	snakeBody body[100];
	int snakeSize;
	sf::Texture texture;

	bool pause = false;
	bool _isOnPill = false;

};

extern bool gameOver;
extern int scores;
extern int blockSize;
extern int N;
extern int M;
extern bool isTeleportsOn;

#endif // !SNAKE_H

