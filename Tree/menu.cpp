#include "menu.h"



void menu::mainSequencion()
{
	this->buildSeq();
	this->findSeq();
	this->addSeq();
	this->delSeq();
	this->printSeq();
	this->removeSeq();
}

void menu::buildSeq()
{
	fileHandler * fileSaver = new fileHandler;
	treeControler * controler = new treeControler;
	fileSaver->setFileName("buildBST");
	int data = 250;
	for (int i = 0; i < 10; i++) {
		double time = 0;
		controler->setCount(data);
		fileSaver->buildOutputData(std::to_string(data));
		for (int x = 0; x < 10; x++) {
			//std::cout << "#" << i << "##" << x << " ";
			time += controler->buildBST();
		}
		time /= 10;
		data += 250;
		std::cout << std::endl << time << std::endl;
		fileSaver->buildOutputData(std::to_string(time));
	}
	fileSaver->saveDataToFile();
	fileSaver->setFileName("buildAVL");
	data = 250;
	for (int i = 0; i < 10; i++) {
		double time = 0;
		controler->setCount(data);
		fileSaver->buildOutputData(std::to_string(data));
		for (int x = 0; x < 10; x++) {
			//std::cout << "#" << i << "##" << x << " ";
			time += controler->buildAVL();
		}
		time /= 10;
		data += 250;
		fileSaver->buildOutputData(std::to_string(time));
	}
	fileSaver->saveDataToFile();
	fileSaver->setFileName("buildDEG");
	data = 250;
	for (int i = 0; i < 10; i++) {
		double time = 0;
		controler->setCount(data);
		fileSaver->buildOutputData(std::to_string(data));
		for (int x = 0; x < 10; x++) {
			//std::cout << "#" << i << "##" << x << " ";
			time += controler->buildDegeneratedBST();
		}
		time /= 10;
		data += 250;
		fileSaver->buildOutputData(std::to_string(time));
	}
	fileSaver->saveDataToFile();
}

void menu::findSeq()
{
	fileHandler * fileSaver = new fileHandler;
	treeControler * controler = new treeControler;
	fileSaver->setFileName("findBST");
	int data = 250;
	for (int i = 0; i < 10; i++) {
		double time = 0;
		controler->setCount(data);
		fileSaver->buildOutputData(std::to_string(data));
		for (int x = 0; x < 10; x++) {
			//std::cout << "#" << i << "##" << x << " ";
			time += controler->finderBST();
		}
		time /= 10;
		data += 250;
		std::cout << "#" << i << std::endl << time << std::endl;
		fileSaver->buildOutputData(std::to_string(time));
	}
	fileSaver->saveDataToFile();
	fileSaver->setFileName("findAVL");
	data = 250;
	for (int i = 0; i < 10; i++) {
		double time = 0;
		controler->setCount(data);
		fileSaver->buildOutputData(std::to_string(data));
		for (int x = 0; x < 10; x++) {
			//std::cout << "#" << i << "##" << x << " ";
			time += controler->finderAVL();
		}
		time /= 10;
		data += 250;
		std::cout << "#" << i << std::endl << time << std::endl;
		fileSaver->buildOutputData(std::to_string(time));
	}
	fileSaver->saveDataToFile();
	fileSaver->setFileName("findDEG");
	data = 250;
	for (int i = 0; i < 10; i++) {
		double time = 0;
		controler->setCount(data);
		fileSaver->buildOutputData(std::to_string(data));
		for (int x = 0; x < 10; x++) {
			time += controler->finderDegeneratedBST();
		}
		time /= 10;
		data += 250;
		std::cout << "#" << i << std::endl << time << std::endl;
		fileSaver->buildOutputData(std::to_string(time));
	}
	fileSaver->saveDataToFile();
}

void menu::addSeq()
{	
	fileHandler * fileSaver = new fileHandler;
	treeControler * controler = new treeControler;
	fileSaver->setFileName("insBST");
	int data = 250;
	for (int i = 0; i < 10; i++) {
		double time = 0;
		controler->setCount(data);
		fileSaver->buildOutputData(std::to_string(data));
		for (int x = 0; x < 10; x++) {
			//std::cout << "#" << i << "##" << x << " ";
			time += controler->insertionBST();
		}
		time /= 10;
		data += 250;
		std::cout << "#" << i << std::endl << time << std::endl;
		fileSaver->buildOutputData(std::to_string(time));
	}
	fileSaver->saveDataToFile();
	fileSaver->setFileName("insAVL");
	data = 250;
	for (int i = 0; i < 10; i++) {
		double time = 0;
		controler->setCount(data);
		fileSaver->buildOutputData(std::to_string(data));
		for (int x = 0; x < 10; x++) {
			std::cout << "#" << i << "##" << "1" << " " << std::endl;
			time += controler->insertionAVL();
		}
		time /= 10;
		data += 250;
		std::cout << "#" << i << std::endl << time << std::endl;
		fileSaver->buildOutputData(std::to_string(time));
	}
	fileSaver->saveDataToFile();
	fileSaver->setFileName("insDEG");
	data = 250;
	for (int i = 0; i < 10; i++) {
		double time = 0;
		controler->setCount(data);
		fileSaver->buildOutputData(std::to_string(data));
		for (int x = 0; x < 10; x++) {
			time += controler->insertionDegeneratedBST();
		}
		time /= 10;
		data += 250;
		std::cout << "#" << i << std::endl << time << std::endl;
		fileSaver->buildOutputData(std::to_string(time));
	}
	fileSaver->saveDataToFile();
}

void menu::delSeq()
{
	fileHandler * fileSaver = new fileHandler;
	treeControler * controler = new treeControler;
	fileSaver->setFileName("delBST");
	int data = 250;
	
	for (int i = 0; i < 10; i++) {
		double time = 0;
		controler->setCount(data);
		fileSaver->buildOutputData(std::to_string(data));
		for (int x = 0; x < 10; x++) {
			//std::cout << "#" << i << "##" << x << " ";
			time += controler->deletionBST();
		}
		time /= 10;
		data += 250;
		std::cout << "#" << i << std::endl << time << std::endl;
		fileSaver->buildOutputData(std::to_string(time));
	}
	fileSaver->saveDataToFile();
	fileSaver->setFileName("delAVL");
	data = 250;
	for (int i = 0; i < 10; i++) {
		double time = 0;
		controler->setCount(data);
		fileSaver->buildOutputData(std::to_string(data));
		for (int x = 0; x < 10; x++) {
			//std::cout << "#" << i << "##" << x << " ";
			time += controler->deletionAVL();
		}
		time /= 10;
		data += 250;
		std::cout << "#" << i << std::endl << time << std::endl;
		fileSaver->buildOutputData(std::to_string(time));
	}
	fileSaver->saveDataToFile();
	fileSaver->setFileName("delDEG");
	data = 250;
	for (int i = 0; i < 10; i++) {
		double time = 0;
		controler->setCount(data);
		fileSaver->buildOutputData(std::to_string(data));
		for (int x = 0; x < 10; x++) {
			time += controler->deletionDegeneratedBST();
		}
		time /= 10;
		data += 250;
		std::cout << "#" << i << std::endl << time << std::endl;
		fileSaver->buildOutputData(std::to_string(time));
	}
	fileSaver->saveDataToFile();
}

void menu::printSeq()
{
	treeControler * controler = new treeControler;
	controler->setCount(250);
	controler->printBST();
	std::cout << std::endl;
	controler->printAVL();
	std::cout << std::endl;
	controler->printDBST();
	delete controler;
}

void menu::removeSeq()
{
	treeControler * controler = new treeControler;
	controler->setCount(250);
	controler->removeBST();
	std::cout << "1"<< std::endl;
	controler->removeAVL();
	std::cout << "2" << std::endl;
	controler->removeDBST();
	delete controler;
}

menu::menu()
{
	this->mainSequencion();
}


menu::~menu()
{
}
