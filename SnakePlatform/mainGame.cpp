#include "mainGame.h"


void mainGame::Initiate(sf::RenderWindow* window)
{
	snake = new Snake();
	map.Load(backgroundFileName);
}

void mainGame::Render(sf::RenderWindow* window)
{
	window->draw(map);
	snake->Render(window);
}

void mainGame::Update(sf::RenderWindow* window)
{
	snake->getInput();
	snake->Update();
}

void mainGame::Destroy(sf::RenderWindow* window)
{
	delete snake;
	snake = NULL;
}

void mainGame::Reset(sf::RenderWindow* window)
{
}
