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
	mainGame(sf::RenderWindow* window);
	void Initiate();
	void Update();
	void Render();
	void Destroy();
	void Reset();
	~mainGame();

private:

	sf::RenderWindow* window;
	Snake* snake;
	Map map;
	VertexMap vertexMap;
	Food food;
};

extern std::string backgroundFileName;
