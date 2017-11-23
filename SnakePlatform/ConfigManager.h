#pragma once
#include <string>
#include <sys/stat.h>
#include <fstream>
#include <iostream>


class ConfigManager
{
public:
	ConfigManager();
	~ConfigManager();
	bool loadConfigFile();
	bool checkIfLineIsValidCommand(const std::string& command);
	std::string setFlagForCommand(const std::string& command);
	bool checkIfFileIsValid();
	void setDefaultValuesToFile();
	bool createNewConfigFile();
	bool fileExists();
	void setFileName(std::string fileName);
	bool saveConfig();


private:
	std::string fileName;
	std::string soundFX = "SoundFX";
	std::string music = "Music";
	std::string teleports = "Teleports";
	std::string difficulty = "Difficulty";
	std::string flagOn = "\"1\"";
	std::string flagOff = "\"0\"";
	std::string normalDifficulty = "\"normal\"";
	std::string easyDifficulty = "\"easy\"";
	std::string hardDifficulty = "\"hard\"";

	std::string commands[4] = { "SoundFX", "Music", "Teleports", "Difficulty" };
};

extern bool isTeleportsOn;
extern bool isMusicOn;
extern bool isSoundFxOn;
extern int globalDifficulty;


