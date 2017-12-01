#include "mainGame.h"


mainGame::mainGame(sf::RenderWindow* window)
{
	this->window = window;
	//this->blockSize = blockSize;
}

void mainGame::Initiate()
{
	this->width = window->getSize().x / blockSize;
	this->height = window->getSize().y / blockSize;
	snake = new Snake(blockSize, width, height);
	map.Load(backgroundFileName, width, height, blockSize);
	food = new Food(blockSize, width, height);
	food->setRandomPosition();
	vertexMap = new VertexMap(width, height, blockSize);
}

void mainGame::Render()
{
	if (snake->isOnPill())
		vertexMap->Update(window);
	else
		window->draw(map);

	snake->Render(window);
	window->draw(*food);
}

void mainGame::Update()
{
	snake->getInput();
	snake->Update();
	food->Update();

	if (snake->isDead())
		gameOver = true;

	if (snake->body[0].x == food->getPosition().x / blockSize && snake->body[0].y == food->getPosition().y / blockSize)
	{
		snake->scores++;
		snake->incrementSnakeSize();
		food->setRandomPosition();
		snake->setIsOnPill(true);
		vertexMap->startEffect(sf::Vector2i(snake->body[0].x * blockSize, snake->body[0].y * blockSize));

		if (isTeleportsOn)
		{
			snake->body[0].x = rand() % width;
			snake->body[0].y = rand() % height;
			snake->direction = rand() % 4;
		}
	}
}

void mainGame::Destroy()
{
	delete snake;
	delete food;
	delete vertexMap;
	snake = NULL;
	food = NULL;
	vertexMap = NULL;
}

void mainGame::Reset()
{
}

mainGame::~mainGame()
{

}
