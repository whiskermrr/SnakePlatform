#pragma once
#include "state.h"
#include "Snake.h"
#include "Map.h"
#include "VertexMap.h"
#include "Food.h"


class mainGame :
	public State
{
public:
	
	void Initiate(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
	void Reset(sf::RenderWindow* window);

private:

	Snake* snake;
	Map map;
	VertexMap vertexMap;
	Food food;
};

extern std::string backgroundFileName;
