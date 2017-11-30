#pragma once

#include "State.h"
#include "mainGame.h"

class gameState
{
public:

	gameState()
	{
		this->state = NULL;
	}

	void Update()
	{
		if (this->state != NULL)
		{
			this->state->Update();
		}
	}

	void Render()
	{
		if (this->state != NULL)
		{
			this->state->Render();
		}
	}

	void setState(State* state)
	{
		if (this->state != NULL)
		{
			this->state->Destroy();
		}

		this->state = state;

		if (this->state != NULL)
		{
			this->state->Initiate();
		}
	}

	void Destroy()
	{
		if (this->state != NULL)
		{
			this->state->Destroy();
		}
	}

	void setWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}

	sf::RenderWindow* getWindow()
	{
		return this->window;
	}

	~gameState()
	{
		if (this->state != NULL)
		{
			this->state->Destroy();
		}
	}

private:

	sf::RenderWindow* window;
	State* state;
};

extern gameState mainState;
extern bool gameExit;