#pragma once
#include <SFML/Graphics.hpp>


class Food : public sf::Sprite
{
public:
	Food();
	void setRandomPosition();
	void Update();
	~Food();

private:
	sf::Texture texture;
	sf::Vector2i source;
};

extern int blockSize;
extern int N;
extern int M;

