#include "mainGame.h"


mainGame::mainGame(sf::RenderWindow* window)
{
	this->window = window;
}

void mainGame::Initiate()
{
	snake = new Snake();
	map.Load(backgroundFileName);
	food.setRandomPosition();
}

void mainGame::Render()
{
	if (snake->isOnPill())
		vertexMap.Update(window);
	else
		window->draw(map);

	snake->Render(window);
	window->draw(food);
}

void mainGame::Update()
{
	snake->getInput();
	snake->Update();
	food.Update();

	if (snake->body[0].x == food.getPosition().x / blockSize && snake->body[0].y == food.getPosition().y / blockSize)
	{
		scores++;
		snake->incrementSnakeSize();
		food.setRandomPosition();
		snake->setIsOnPill(true);
		vertexMap.startEffect(sf::Vector2i(snake->body[0].x * blockSize, snake->body[0].y * blockSize));

		if (isTeleportsOn)
		{
			snake->body[0].x = rand() % N;
			snake->body[0].y = rand() % M;
			snake->direction = rand() % 4;
		}
	}
}

void mainGame::Destroy()
{
	delete snake;
	snake = NULL;
}

void mainGame::Reset()
{
}

mainGame::~mainGame()
{

}
