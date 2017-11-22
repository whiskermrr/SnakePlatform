#include "Snake.h"

Snake::Snake()
{
	srand(time(NULL));
	snakeSize = 3;
	direction = DOWN;
	texture.loadFromFile("resources/snake.png");
	this->setTexture(texture);

	for (int i = 0; i <= snakeSize; i++)
	{
		body[i].x = 10;
		body[i].y = 10 - i;
	}
}

void Snake::Update()
{
	checkCollisionWithBorders();
	updateBody();
	checkCollisionWithItself();
}

void Snake::checkCollisionWithItself()
{
	for (int i = 2; i <= snakeSize; i++)
	{
		if (body[0].x == body[i].x && body[0].y == body[i].y)
			gameOver = true;
	}
}

void Snake::checkCollisionWithBorders()
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

void Snake::updateBody()
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

void Snake::incrementSnakeSize()
{
	snakeSize += 1;
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
