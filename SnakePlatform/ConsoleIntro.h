#pragma once
#include <string>
#include <fstream>
#include <stdlib.h>
#include "state.h"
#include "ConsoleMenu.h"
class ConsoleIntro : public State
{
public:
	ConsoleIntro(unsigned int width, unsigned int height);
	void Initiate();
	void Update();
	void Render();
	void RenderLogo();
	void DestroyLogo(int x, int y);
	void FlickerLogo();
	void SimulateTyping();
	void Destroy();
	~ConsoleIntro();

public:
	unsigned int width;
	unsigned int height;
	unsigned int rows;
	unsigned int columns;
	unsigned int startWindowX = 10;
	unsigned int startWindowY = 50;
	bool end = false;
	int flicker = 1;
	int counterFlicker = 30;
	char* logo;
};

