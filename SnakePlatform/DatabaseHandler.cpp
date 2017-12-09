#include "DatabaseHandler.h"



DatabaseHandler::DatabaseHandler()
{
}

bool DatabaseHandler::fileExists()
{
	struct stat buffer;

	if (stat(fileName.c_str(), &buffer) != -1)
		return true;

	return false;
}

bool DatabaseHandler::createNewDatabase()
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

void DatabaseHandler::setFileName(std::string fileName)
{
	this->fileName = fileName;
}

bool DatabaseHandler::addRecordToDatabase(std::string nickname, int difficulty, bool teleports, int scores)
{
	std::fstream file;
	file.open(fileName.c_str(), std::ofstream::app);

	if (!file.good())
		return false;

	std::string sDifficulty;

	switch (difficulty)
	{
	case 1:
		sDifficulty = "EASY";
		break;

	case 2:
		sDifficulty = "NORMAL";
		break;

	case 3:
		sDifficulty = "HARD";
		break;

	default:
		sDifficulty = "ERR";
		break;
	}

	file << nickname << " " << scores << " " << sDifficulty << " " << (teleports ? "ON" : "OFF") << std::endl;
	file.close();
	
	return true;
}

std::vector<std::string> DatabaseHandler::getDataFromDatabase()
{
	std::fstream file;
	std::vector<std::string> data;
	std::string record;

	if (!fileExists())
	{
		if (!createNewDatabase())
			return data;
	}

	file.open(fileName.c_str());

	while (!file.eof())
	{
		getline(file, record);
		data.push_back(record);
	}

	return data;
}


DatabaseHandler::~DatabaseHandler()
{
}
