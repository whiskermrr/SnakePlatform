#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h>

class State
{
public:
	
	virtual void Initiate(sf::RenderWindow* window)
	{
	}

	virtual void Update(sf::RenderWindow* window)
	{
	}

	virtual void Render(sf::RenderWindow* window)
	{
	}

	virtual void Destroy(sf::RenderWindow* window)
	{
	}
};