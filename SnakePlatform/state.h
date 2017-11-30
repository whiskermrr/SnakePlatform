#pragma once

#include <SFML/Graphics.hpp>
#include <Windows.h>

class State
{
public:
	
	virtual void Initiate()
	{
	}

	virtual void Update()
	{
	}

	virtual void Render()
	{
	}

	virtual void Destroy()
	{
	}
};