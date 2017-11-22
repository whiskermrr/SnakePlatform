#include "Food.h"



Food::Food()
{
	texture.loadFromFile("resources/teleport.png");
	setTexture(texture);
}

void Food::setRandomPosition()
{
	srand(time(NULL));
	int x = rand() % N;
	int y = rand() % M;

	setPosition(sf::Vector2f(x * blockSize, y * blockSize));
}

Food::~Food()
{
}
