#include "MainMenu.h"



MainMenu::MainMenu()
{
}

void MainMenu::Initiate(sf::RenderWindow* window)
{
	font.loadFromFile("resources/font2.ttf");
	tTitle.setFont(font);
	tTitle.setCharacterSize(titleSize);
	tTitle.setOrigin(tTitle.getGlobalBounds().width / 2, tTitle.getGlobalBounds().height / 2);
	tTitle.setPosition(window->getSize().x / 4, window->getSize().y / 4);
	tTitle.setString("SNAK3");
	tTitle.setFillColor(sf::Color::White);

	tPlay.setFont(font);
	tPlay.setCharacterSize(textSize);
	tPlay.setOrigin(tTitle.getGlobalBounds().width / 2, tTitle.getGlobalBounds().height / 2);
	tPlay.setPosition(window->getSize().x / 4, window->getSize().y / 2);
	tPlay.setString("Play");
	tPlay.setFillColor(sf::Color::White);

	tOptions.setFont(font);
	tOptions.setCharacterSize(textSize);
	tOptions.setOrigin(tTitle.getGlobalBounds().width / 2, tTitle.getGlobalBounds().height / 2);
	tOptions.setPosition(window->getSize().x / 4, window->getSize().y / 2 + (textSize * 1.25f));
	tOptions.setString("Options");
	tOptions.setFillColor(sf::Color::White);

	tQuit.setFont(font);
	tQuit.setCharacterSize(textSize);
	tQuit.setOrigin(tTitle.getGlobalBounds().width / 2, tTitle.getGlobalBounds().height / 2);
	tQuit.setPosition(window->getSize().x / 4, window->getSize().y / 2 + (2 * textSize * 1.25f));
	tQuit.setString("Quit");
	tQuit.setFillColor(sf::Color::White);
}

void MainMenu::Update(sf::RenderWindow* window)
{
	if (clock.getElapsedTime().asSeconds() >= 1.0f / KEY_FPS)
	{
		tPlay.setFillColor(sf::Color::White);
		tOptions.setFillColor(sf::Color::White);
		tQuit.setFillColor(sf::Color::White);

		switch (selected)
		{
		case 1:
			tPlay.setFillColor(sf::Color::Cyan);
			upKey = false;
			break;

		case 2:
			tOptions.setFillColor(sf::Color::Cyan);
			upKey = true;
			downKey = true;
			break;

		case 3:
			tQuit.setFillColor(sf::Color::Cyan);
			downKey = false;
			break;

		default:
			break;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && upKey)	selected--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && downKey)	selected++;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			switch (selected)
			{
			case 1:
				mainState.setState(new mainGame());
				break;

			case 2:
				mainState.setState(new OptionsMenu());
				break;

			case 3:
				gameExit = true;
				break;
			}
		}

		clock.restart();
	}
}

void MainMenu::Render(sf::RenderWindow* window)
{
	window->draw(tTitle);
	window->draw(tPlay);
	window->draw(tOptions);
	window->draw(tQuit);
}

void MainMenu::Destroy(sf::RenderWindow* window)
{

}

