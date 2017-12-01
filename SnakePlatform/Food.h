#pragma once
#include <SFML/Graphics.hpp>


class Food : public sf::Sprite
{
public:
	Food(unsigned int blockSize, unsigned int width, unsigned int height);
	void setRandomPosition();
	void Update();
	~Food();

private:
	sf::Texture texture;
	sf::Vector2i source;
	unsigned int blockSize;
	unsigned int width;
	unsigned int height;
};

