#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include "SnakeBase.h"

class Snake : public sf::Sprite, public SnakeBase
{
public:
	Snake(unsigned int blockSize, unsigned int width, unsigned int height);
	void getInput();
	void Render(sf::RenderWindow* window);
	~Snake();

public:
	sf::Texture texture;
	unsigned int blockSize;
};

#endif // !SNAKE_H

