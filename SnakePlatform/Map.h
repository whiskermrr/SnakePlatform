#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Map : public sf::Drawable, public sf::Transformable
{
public:
	Map();
	~Map();
	bool Load(std::string& fileName, unsigned int width, unsigned int height, unsigned int blockSize);

private:
	virtual void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = &texture;
		target.draw(vertexes, states);
	}

	sf::VertexArray vertexes;
	sf::Texture texture;
};

