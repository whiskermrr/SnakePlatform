#include "mainGame.h"


void mainGame::Initiate(sf::RenderWindow* window)
{
	snake = new Snake();
	map = new Map();
}

void mainGame::Render(sf::RenderWindow* window)
{
	map->Render(window);
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
	delete map;
	map = NULL;
	snake = NULL;
}

void mainGame::Reset(sf::RenderWindow* window)
{
	
}
