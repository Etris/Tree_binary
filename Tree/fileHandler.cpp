#include "fileHandler.h"
#include <iostream>
#include <string>
#include <fstream>

fileHandler::fileHandler()
{
	fileName = "";
		data = "";
}


fileHandler::~fileHandler()
{
}

void fileHandler::convertTime(double var)
{
	buildOutputData(std::to_string(var));
}

void fileHandler::setFileName(std::string name)
{
	fileName = name + ".txt";
}

void fileHandler::buildOutputData(std::string text)
{
	if (data.empty() == true) {
		data += text;
	}
	else {
		data += ";";
		data += text;
	}
}

std::string fileHandler::getFileName()
{
	return fileName;
}

void fileHandler::saveDataToFile()
{
	std::ofstream fileOutputHandler;
	fileOutputHandler.open(getFileName());
	if (fileOutputHandler.good() == true) {
		fileOutputHandler << data;
	}
	fileOutputHandler.close();
	data = "";
}

