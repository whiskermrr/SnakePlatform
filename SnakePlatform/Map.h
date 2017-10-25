#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

class Map
{
public:
	Map();
	void Render(sf::RenderWindow* window);
	~Map();

private:
	sf::Texture texutre;
	sf::Sprite tile;
	int N;
	int M;
};

extern sf::Vector2i screenResolution;
extern int blockSize;

#endif // !MAP_H

