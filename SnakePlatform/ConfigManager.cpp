#include "ConfigManager.h"



ConfigManager::ConfigManager()
{
	fileName = "config/config.cfg";
}


ConfigManager::~ConfigManager()
{
}

bool ConfigManager::fileExists()
{
	struct stat buffer;

	if (stat(fileName.c_str(), &buffer) != -1)
		return true;

	return false;
}

bool ConfigManager::createNewConfigFile()
{
	std::ofstream file(fileName.c_str());

	if (file.good())
	{
		file.close();
		return true;
	};

	file.close();
	return false;
}

void ConfigManager::setDefaultValuesToFile()
{
	std::ofstream file;
	file.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);
	file << soundFX << " " << flagOn << std::endl;
	file << music << " " << flagOn << std::endl;
	file << teleports << " " << flagOff << std::endl;
	file << difficulty << " " << normalDifficulty << std::endl;
	file.close();
}

bool ConfigManager::checkIfFileIsValid()
{
	std::fstream file;
	std::string command;
	file.open(fileName.c_str());

	if (!file.good())
		return false;

	while (!file.eof())
	{
		getline(file, command);

		if (command.empty())
			continue;

		if (!checkIfLineIsValidCommand(command))
			return false;
	}

	file.close();

	return true;
}

std::string ConfigManager::setFlagForCommand(const std::string& command)
{
	if (command.find(flagOff) != std::string::npos)
	{
		return flagOff;
	}
	else if (command.find(flagOn) != std::string::npos)
	{
		return flagOn;
	}
	else if (command.find(normalDifficulty) != std::string::npos)
	{
		return normalDifficulty;
	}
	else if (command.find(hardDifficulty) != std::string::npos)
	{
		return hardDifficulty;
	}
	else if (command.find(easyDifficulty) != std::string::npos)
	{
		return easyDifficulty;
	}

	return "";
}

bool ConfigManager::checkIfLineIsValidCommand(const std::string& command)
{
	std::string flag;

	for (int i = 0; i < 4; i++)
	{
		if (command.find(commands[i]) != std::string::npos)
		{
			flag = setFlagForCommand(command);

			if (flag == flagOn || flag == flagOff)
			{
				if (command == commands[i] + " " + flag)
				{
					switch (i)
					{
					case 0:
						isSoundFxOn = flag == flagOn;
						break;
					case 1:
						isMusicOn = flag == flagOn;
						break;
					case 2:
						isTeleportsOn = flag == flagOn;
						break;
					}
					return true;
				}
				else
					return false;
			}

			else if (flag == normalDifficulty || flag == hardDifficulty || flag == easyDifficulty)
			{
				if (command == difficulty + " " + flag)
				{
					if (flag == easyDifficulty)
					{
						globalDifficulty = 1;
						return true;
					}
					else if (flag == normalDifficulty)
					{
						globalDifficulty = 2;
						return true;
					}
					else if (flag == hardDifficulty)
					{
						globalDifficulty = 3;
						return true;
					}
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
	}

	return false;
}

bool ConfigManager::loadConfigFile()
{
	if (!fileExists())
	{
		if (!createNewConfigFile())
			return false;

		setDefaultValuesToFile();
	}

	if (!checkIfFileIsValid())
	{
		setDefaultValuesToFile();

		return checkIfFileIsValid();
	}

	return true;
}

void ConfigManager::setFileName(std::string fileName)
{
	this->fileName = fileName;
}

bool ConfigManager::saveConfig()
{
	std::fstream file;
	file.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);

	if (!file.good())
		return false;
	
	std::string diff;

	if (globalDifficulty == 1)		diff = easyDifficulty;
	else if (globalDifficulty == 2)	diff = normalDifficulty;
	else if (globalDifficulty == 3)	diff = hardDifficulty;

	file << soundFX << " " << (isSoundFxOn ? flagOn : flagOff) << std::endl;
	file << music << " " << (isMusicOn ? flagOn : flagOff) << std::endl;
	file << teleports << " " << (isTeleportsOn ? flagOn : flagOff) << std::endl;
	file << difficulty << " " << diff << std::endl;
	file.close();

	return true;
}
