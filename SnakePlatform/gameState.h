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
			this->state->Update(this->window);
		}
	}

	void Render()
	{
		if (this->state != NULL)
		{
			this->state->Render(this->window);
		}
	}

	void setWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}

	void setState(State* state)
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}

		this->state = state;

		if (this->state != NULL)
		{
			this->state->Initiate(this->window);
		}
	}

	void Destroy()
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}
	}

	~gameState()
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}
	}

private:

	sf::RenderWindow* window;
	State* state;
};

extern gameState mainState;
extern bool gameExit;