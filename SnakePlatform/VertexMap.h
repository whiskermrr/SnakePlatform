#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <math.h>


class VertexMap
{
public:
	VertexMap();
	~VertexMap();
	void Update(sf::RenderWindow* window);
	void startEffect(sf::Vector2i mouseCoords);

private:

	sf::VertexArray vertexes;
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

extern sf::Vector2i screenResolution;
extern int blockSize;


