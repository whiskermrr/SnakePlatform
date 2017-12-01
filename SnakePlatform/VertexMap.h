#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <math.h>


class VertexMap
{
public:
	VertexMap(unsigned int width, unsigned int height, unsigned int blockSize);
	~VertexMap();
	void Update(sf::RenderWindow* window);
	void startEffect(sf::Vector2i mouseCoords);

private:

	sf::VertexArray vertexes;
	unsigned int blockSize;
	int width = 0;
	int height = 0;
	int west;
	int east;
	int north;
	int south;
	int effectLevel = 6;
	sf::Color colors[7];
	bool isEffectOn;
};


