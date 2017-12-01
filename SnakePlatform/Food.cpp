#include "Food.h"



Food::Food(unsigned int blockSize, unsigned int width, unsigned int height)
{
	this->blockSize = blockSize;
	this->width = width;
	this->height = height;
	texture.loadFromFile("resources/teleports_extended.png");
	setTexture(texture);
	source.x = 0;
	source.y = 0;
	setTextureRect(sf::IntRect(source.x * blockSize, source.y * blockSize, blockSize, blockSize));
}

void Food::setRandomPosition()
{
	srand(time(NULL));
	int x = rand() % width;
	int y = rand() % height;

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
