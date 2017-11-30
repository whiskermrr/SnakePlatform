#include "Snake.h"

Snake::Snake()
{
	srand(time(NULL));
	texture.loadFromFile("resources/snake.png");
	this->setTexture(texture);

	for (int i = 0; i <= snakeSize; i++)
	{
		body[i].x = 10;
		body[i].y = 10 - i;
	}
}

void Snake::Render(sf::RenderWindow* window)
{
	for (int i = 0; i <= snakeSize; i++)
	{
		setPosition(body[i].x * blockSize, body[i].y * blockSize);
		window->draw(*this);
	}
}

void Snake::getInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && direction != DOWN)
		direction = UP;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && direction != UP)
		direction = DOWN;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && direction != RIGHT)
		direction = LEFT;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && direction != LEFT)
		direction = RIGHT;
}

Snake::~Snake()
{
}
