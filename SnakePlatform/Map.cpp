#include "Map.h"



Map::Map()
{
	texutre.loadFromFile("resources/background.png");
	tile.setTexture(texutre);
	N = screenResolution.x / blockSize;
	M = screenResolution.y / blockSize;
}


void Map::Render(sf::RenderWindow* window)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			tile.setPosition(i * blockSize, j * blockSize);
			window->draw(tile);
		}
	}
}

Map::~Map()
{
}
