#include "treeControler.h"
#include <iostream>


treeControler::treeControler()
{
}


treeControler::~treeControler()
{
}

double treeControler::buildBST()
{
	numberGenerator * gen = new numberGenerator;
	gen->setNumbers(this->getCount());
	gen->genereteArray();
	binaryTNode * tree = new binaryTNode;
	timer * timeSet = new timer;
	arr = gen->getCopyOfArray();
	timeSet->start();
	for (int i = 0; i < this->getCount(); i++) {
		bool x = tree->insertNode(arr[i]);
		if (x = true) std::cout << "#" << i << ", ";
	}
	timeSet->end();
	double times = timeSet->getLastTime();
	delete gen, tree, timeSet;
	return times;
}

double treeControler::buildAVL()
{
	numberGenerator * gen = new numberGenerator;
	gen->setNumbers(this->getCount());
	gen->genereteSortedArray();
	avlNode * tree = new avlNode;
	timer * timeSet = new timer;
	tree->setArray(gen->getCopyOfArray());
	timeSet->start();
	tree->buildNew(this->getCount());
	timeSet->end();
	double times = timeSet -> getLastTime();
	delete gen, tree, timeSet;
	return times;
}

double treeControler::buildDegeneratedBST()
{
	numberGenerator * gen = new numberGenerator;
	gen->setNumbers(this->getCount());
	gen->genereteArray();
	binaryTNode * tree = new binaryTNode;
	timer * timeSet = new timer;
	arr = gen->getCopyOfArray();
	timeSet->start();
	for (int i = 0; i < this->getCount(); i++) {
		bool x = tree->insertDegenerated(arr[i]);
		if (x = true) std::cout << "#" << i << ", ";
	}
	timeSet->end();
	double times = timeSet->getLastTime();
	delete gen, tree, timeSet;
	return times;
}

double treeControler::finderBST()
{
	int tmp = this->getCount() / 10;
	srand(time(nullptr));
	numberGenerator * gen = new numberGenerator;
	gen->setNumbers(this->getCount());
	gen->genereteArray();
	binaryTNode * tree = new binaryTNode;
	timer * timeSet = new timer;
	arr = gen->getCopyOfArray();
	for (int i = 0; i < this->getCount(); i++) {
		bool x = tree->insertNode(arr[i]);
		if (x = true) std::cout << "#" << i << ", ";
	}
	timeSet->start();
	for (int a = 0; a < tmp; a++) {
		int abs = rand() % (20000 - 1) + 0;
		bool c = tree->find(abs);
	}
	timeSet->end();
	double times = timeSet->getLastTime();
	delete gen, tree, timeSet;
	return times;
}

double treeControler::finderAVL()
{
	int tmp = this->getCount() / 10;
	srand(time(nullptr));
	numberGenerator * gen = new numberGenerator;
	gen->setNumbers(this->getCount());
	gen->genereteSortedArray();
	avlNode * tree = new avlNode;
	timer * timeSet = new timer;
	tree->setArray(gen->getCopyOfArray());
	tree->buildNew(this->getCount());
	timeSet->start();
	for (int a = 0; a < tmp; a++) {
		int abs = rand() % (20000 - 1) + 0;
		bool c = tree->searchKey(abs);
	}
	timeSet->end();
	double times = timeSet->getLastTime();
	delete gen, tree, timeSet;
	return times;
}

double treeControler::finderDegeneratedBST()
{
}

double treeControler::insertionBST()
{

}

double treeControler::insertionAVL()
{
}

double treeControler::insertionDegeneratedBST()
{
}

double treeControler::deletionBST()
{
}

double treeControler::deletionAVL()
{
}

double treeControler::deletionDegeneratedBST()
{
}

void treeControler::printBST()
{
}

void treeControler::printAVL()
{
}

void treeControler::printDBST()
{
}

void treeControler::removeBST()
{
}

void treeControler::removeAVL()
{
}

void treeControler::removeDBST()
{
}

void treeControler::setArray(int[])
{
}

void treeControler::setCount(int value)
{
	count = value;
}

int treeControler::getCount()
{
	return count;
}
