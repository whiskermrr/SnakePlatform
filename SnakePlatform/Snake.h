#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include "SnakeBase.h"

class Snake : public sf::Sprite, public SnakeBase
{
public:
	Snake();
	void getInput();
	void Render(sf::RenderWindow* window);
	~Snake();

public:
	sf::Texture texture;
};

#endif // !SNAKE_H

