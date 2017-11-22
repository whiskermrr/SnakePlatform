#pragma once
#include <SFML/Graphics.hpp>


class Food : public sf::Sprite
{
public:
	Food();
	void setRandomPosition();
	~Food();

private:
	sf::Texture texture;
};

extern int blockSize;
extern int N;
extern int M;

