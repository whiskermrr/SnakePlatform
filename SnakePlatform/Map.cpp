#include "Map.h"
#include <stdlib.h>

Map::Map()
{

}

bool Map::Load(std::string& fileName)
{
	if (!texture.loadFromFile(fileName))
		return false;

	vertexes.setPrimitiveType(sf::Quads);
	int width = screenResolution.x / blockSize;
	int height = screenResolution.y / blockSize;
	vertexes.resize(width * height * 4);

	srand(time(NULL));

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			sf::Vertex* vertex = &vertexes[(i + j * width) * 4];

			vertex[0].position = sf::Vector2f(i * blockSize, j * blockSize);
			vertex[1].position = sf::Vector2f((i + 1) * blockSize, j * blockSize);
			vertex[2].position = sf::Vector2f((i + 1) * blockSize, (j + 1) * blockSize);
			vertex[3].position = sf::Vector2f(i * blockSize, (j + 1) * blockSize);

			vertex[0].texCoords = sf::Vector2f(0, 0);
			vertex[1].texCoords = sf::Vector2f(blockSize, 0);
			vertex[2].texCoords = sf::Vector2f(blockSize, blockSize);
			vertex[3].texCoords = sf::Vector2f(0, blockSize);
		}
	}

	return true;
}

Map::~Map()
{
}