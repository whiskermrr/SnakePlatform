#include "OptionsMenu.h"



OptionsMenu::OptionsMenu(ConfigManager* configManager)
{
	this->configManager = configManager;
}

void OptionsMenu::Initiate(sf::RenderWindow* window)
{
	font.loadFromFile("resources/font2.ttf");
	tDifficulty.setFont(font);
	tDifficulty.setCharacterSize(textSize);
	tDifficulty.setOrigin(window->getSize().x / 4, window->getSize().y / 4);
	tDifficulty.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	tDifficulty.setString("Difficulty: NORMAL");

	tTeleports.setFont(font);
	tTeleports.setCharacterSize(textSize);
	tTeleports.setOrigin(window->getSize().x / 4, window->getSize().y / 4);
	tTeleports.setPosition(window->getSize().x / 2, window->getSize().y / 2 + (textSize * 1.45f));

	tMusic.setFont(font);
	tMusic.setCharacterSize(textSize);
	tMusic.setOrigin(window->getSize().x / 4, window->getSize().y / 4);
	tMusic.setPosition(window->getSize().x / 2, window->getSize().y / 2 + (2 * textSize * 1.45f));
	
	tSoundFX.setFont(font);
	tSoundFX.setCharacterSize(textSize);
	tSoundFX.setOrigin(window->getSize().x / 4, window->getSize().y / 4);
	tSoundFX.setPosition(window->getSize().x / 2, window->getSize().y / 2 + (3 * textSize * 1.45f));

	tBack.setFont(font);
	tBack.setCharacterSize(textSize);
	tBack.setOrigin(window->getSize().x / 4, window->getSize().y / 4);
	tBack.setPosition(window->getSize().x / 2, window->getSize().y / 2 + (5 * textSize * 1.45f));
	tBack.setString("Back");

	setTextStrings();
}

void OptionsMenu::Update(sf::RenderWindow* window)
{
	if (clock.getElapsedTime().asSeconds() >= 1.0f / KEY_FPS)
	{
		setTextColorsWhite();
		getInput();
		setTextStrings();
		updateMenuFunctionalityAndSetProperColors();
		clock.restart();
	}
}

void OptionsMenu::setTextColorsWhite()
{
	tDifficulty.setFillColor(sf::Color::White);
	tTeleports.setFillColor(sf::Color::White);
	tMusic.setFillColor(sf::Color::White);
	tSoundFX.setFillColor(sf::Color::White);
	tBack.setFillColor(sf::Color::White);
}

void OptionsMenu::setTextStrings()
{
	std::string teleports = isTeleportsOn ? "ON" : "OFF";
	std::string music = isMusicOn ? "ON" : "OFF";
	std::string soundFx = isSoundFxOn ? "ON" : "OFF";
	std::string difficulty = "";

	switch (globalDifficulty)
	{
	case 1:
		difficulty = "EASY";
		break;
	case 2:
		difficulty = "NORMAL";
		break;
	case 3:
		difficulty = "HARD";
		break;
	}

	tTeleports.setString("Teleports: " + teleports);
	tMusic.setString("Music: " + music);
	tSoundFX.setString("SoundFX: " + soundFx);
	tDifficulty.setString("Difficulty: " + difficulty);
}

void OptionsMenu::updateMenuFunctionalityAndSetProperColors()
{
	switch (selected)
	{
	case 1:
		tDifficulty.setFillColor(sf::Color::Cyan);
		upKey = false;
		break;

	case 2:
		tTeleports.setFillColor(sf::Color::Cyan);
		downKey = true;
		upKey = true;
		break;

	case 3:
		tMusic.setFillColor(sf::Color::Cyan);
		downKey = true;
		upKey = true;
		break;

	case 4:
		tSoundFX.setFillColor(sf::Color::Cyan);
		downKey = true;
		upKey = true;
		break;

	case 5:
		tBack.setFillColor(sf::Color::Cyan);
		downKey = false;
	}
}

void OptionsMenu::getInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && upKey)	selected--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && downKey) selected++;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		switch (selected)
		{
		case 1:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				if (globalDifficulty != 3)
					globalDifficulty++;
			}
			else
			{
				if (globalDifficulty != 1)
					globalDifficulty--;
			}
				
			break;

		case 2:
			(isTeleportsOn ? isTeleportsOn = false : isTeleportsOn = true);
			break;

		case 3:
			(isMusicOn ? isMusicOn = false : isMusicOn = true);
			break;

		case 4:
			(isSoundFxOn ? isSoundFxOn = false : isSoundFxOn = true);
			break;

		default:
			break;
		}
	}

	if (selected == 5 && sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		saveSettings();
		mainState.setState(new MainMenu());
	}
}

void OptionsMenu::saveSettings()
{
	if (!configManager->saveConfig())
		std::cout << "ERROR!" << std::endl;
}

void OptionsMenu::Render(sf::RenderWindow* window)
{
	window->draw(tDifficulty);
	window->draw(tTeleports);
	window->draw(tMusic);
	window->draw(tSoundFX);
	window->draw(tBack);
}

void OptionsMenu::Destroy(sf::RenderWindow* window)
{

}