#include <iostream>
#include <string>
#pragma once
class fileHandler
{
private:
	std::string fileName;
	std::string data;
public:
	fileHandler();
	~fileHandler();
	void convertTime(double);
	void setFileName(std::string);
	void buildOutputData(std::string);
	std::string getFileName();
	void saveDataToFile();
};