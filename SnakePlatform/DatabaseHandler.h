#pragma once
#include <string>
#include <sys/stat.h>
#include <fstream>
#include <iostream>
#include <vector>

class DatabaseHandler
{
public:
	DatabaseHandler();
	bool fileExists();
	void setFileName(std::string fileName);
	bool createNewDatabase();
	bool addRecordToDatabase(std::string nickname, int difficulty, bool teleports, int scores);
	std::vector<std::string> getDataFromDatabase();

	~DatabaseHandler();

private:
	std::string fileName;

};

