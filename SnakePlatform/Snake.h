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
	void setRandomPositionOfFood();
	void Render(sf::RenderWindow* window);
	void checkCollisionWithBorders();
	void checkCollisionWithFood();
	void checkCollisionWithItself();
	void updateBody();
	~Snake();

public:
	int direction;
	snakeBody body[100];
	sf::Sprite food;
	int snakeSize;
	sf::Texture texture;
	sf::Texture foodTexture;

	bool pause = false;

};

extern bool gameOver;
extern int scores;
extern int blockSize;
extern int N;
extern int M;
extern bool isTeleportsOn;

#endif // !SNAKE_H

