#include "VertexMap.h"



VertexMap::VertexMap()
{
	vertexes.setPrimitiveType(sf::LinesStrip);
	width = screenResolution.x / blockSize;
	height = screenResolution.y / blockSize;
	vertexes.resize(4);

	north = height / 2;
	south = height / 2;
	east = width / 2;
	west = width / 2;

	colors[0] = sf::Color(52, 204, 255);
	colors[1] = sf::Color(51, 171, 249);
	colors[2] = sf::Color(47, 141, 255);
	colors[3] = sf::Color(45, 100, 245);
	colors[4] = sf::Color(2, 114, 166);
	colors[5] = sf::Color(1, 96, 104);
	colors[6] = sf::Color(0, 52, 77);

	isEffectOn = false;

	srand(time(NULL));
}

void VertexMap::Update(sf::RenderWindow* window)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			vertexes[0].position = sf::Vector2f(i * blockSize, j * blockSize);
			vertexes[1].position = sf::Vector2f((i + 1) * blockSize, j * blockSize);
			vertexes[2].position = sf::Vector2f((i + 1) * blockSize, (j + 1) * blockSize);
			vertexes[3].position = sf::Vector2f(i * blockSize, (j + 1) * blockSize);

			sf::Color color(0, 35, 51);

			if (isEffectOn)
			{
				for (int k = -6; k <= effectLevel; k++)
				{
					if ((i == west - k || i == east + k) && (j >= north - k && j <= south + k) ||
						((j == north - k || j == south + k) && (i >= west - k && i <= east + k))
						)
					{
						color = colors[abs(k)];
					}
				}
			}

			for (int k = 0; k < 4; k++)
				vertexes[k].color = color;

			window->draw(vertexes);
		}
	}

	if (isEffectOn)
	{
		west -= 4;
		east += 4;
		north -= 4;
		south += 4;

		if (west < 0 && east > width && north < 0 && south > height)
			isEffectOn = false;
	}
}

void VertexMap::startEffect(sf::Vector2i mouseCoords)
{
	north = mouseCoords.y / blockSize;
	south = mouseCoords.y / blockSize;
	west = mouseCoords.x / blockSize;
	east = mouseCoords.x / blockSize;
	isEffectOn = true;
}

VertexMap::~VertexMap()
{
}