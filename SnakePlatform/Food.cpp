#include "Food.h"



Food::Food()
{
	texture.loadFromFile("resources/teleports_extended.png");
	setTexture(texture);
	source.x = 0;
	source.y = 0;
	setTextureRect(sf::IntRect(source.x * blockSize, source.y * blockSize, blockSize, blockSize));
}

void Food::setRandomPosition()
{
	srand(time(NULL));
	int x = rand() % N;
	int y = rand() % M;

	setPosition(sf::Vector2f(x * blockSize, y * blockSize));
}

void Food::Update()
{
	setTextureRect(sf::IntRect(source.x * blockSize, source.y * blockSize, blockSize, blockSize));
	if (++source.x >= 7)
		source.x = 0;
}

Food::~Food()
{
}
