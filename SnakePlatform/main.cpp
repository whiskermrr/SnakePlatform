#include "gameState.h"
#include "mainGame.h"
#include "MainMenu.h"


sf::Vector2i screenResolution(640, 480);
gameState mainState;
bool gameExit;
bool gameOver;
int blockSize = 16;
int scores = 0;
int N = screenResolution.x / blockSize;;
int M = screenResolution.y / blockSize;;
float FPS = 20.0f;
float KEY_FPS = 8.0f;
bool isTeleportsOn = false;
bool isMusicOn = true;
bool isSoundFxOn = true;
int globalDifficulty = 1;

int main()
{
	sf::RenderWindow window(sf::VideoMode(screenResolution.x, screenResolution.y), "Snak3");

	mainState.setWindow(&window);
	mainState.setState(new MainMenu());
	sf::Clock clock;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}	
		}

		if (clock.getElapsedTime().asSeconds() >= 1.0f / FPS)
		{
			window.clear(sf::Color::Black);
			mainState.Update();
			mainState.Render();
			window.display();
			clock.restart();
		}
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
			
		if (gameExit)
		{
			mainState.Destroy();
			window.close();
		}

		if (gameOver)
		{
			//here will be change to another state
			mainState.Destroy();
			window.close();
		}
			
	}

	return 0;
}