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
		int abs = rand() % (200000 - 1) + 0;
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
		int abs = rand() % (200000 - 1) + 0;
		bool c = tree->searchKey(abs);
	}
	timeSet->end();
	double times = timeSet->getLastTime();
	delete gen, tree, timeSet;
	return times;
}

double treeControler::finderDegeneratedBST()
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
		bool x = tree->insertDegenerated(arr[i]);
		if (x = true) std::cout << "#" << i << ", ";
	}
	timeSet->start();
	for (int a = 0; a < tmp; a++) {
		int abs = rand() % (200000 - 1) + 0;
		bool c = tree->find(abs);
	}
	timeSet->end();
	double times = timeSet->getLastTime();
	delete gen, tree, timeSet;
	return times;
}

double treeControler::insertionBST()
{
	int tmp = this->getCount() / 10;
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
	for (int i = 0; i < tmp; i++) {
		tree->insertNode(arr[getCount() - 1 - i]);
	}
	timeSet->end();
	double times = timeSet->getLastTime();
	delete gen, tree, timeSet;
	return times;
}

double treeControler::insertionAVL()
{
	int tmp = this->getCount() / 10;
	numberGenerator * gen = new numberGenerator;
	gen->setNumbers(this->getCount());
	gen->genereteSortedArray();
	avlNode * tree = new avlNode;
	timer * timeSet = new timer;
	tree->setArray(gen->getCopyOfArray());
	tree->buildNew(this->getCount());
	timeSet->start();
	for (int i = 0; i < tmp; i++) {
		tree->insertNode(arr[this->getCount() - 1 - i]);
	}
	timeSet->end();
	double times = timeSet->getLastTime();
	delete gen, tree, timeSet;
	return times;
}

double treeControler::insertionDegeneratedBST()
{
	int tmp = this->getCount() / 10;
	numberGenerator * gen = new numberGenerator;
	gen->setNumbers(this->getCount());
	gen->genereteArray();
	binaryTNode * tree = new binaryTNode;
	timer * timeSet = new timer;
	arr = gen->getCopyOfArray();
	for (int i = 0; i < this->getCount(); i++) {
		bool x = tree->insertDegenerated(arr[i]);
		if (x = true) std::cout << "#" << i << ", ";
	}
	timeSet->start();
	for (int i = 0; i < tmp; i++) {
		bool x = tree->insertDegenerated(arr[this->getCount() - 1 - i]);
	}
	timeSet->end();
	double times = timeSet->getLastTime();
	delete gen, tree, timeSet;
	return times;
}

double treeControler::deletionBST()
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
	for (int i = 0; i < tmp; i++) {
		tree->deleteValue(arr[rand() % (this->getCount() - 1) + 0]);
	}
	timeSet->end();
	double times = timeSet->getLastTime();
	delete gen, tree, timeSet;
	return times;
}

double treeControler::deletionAVL()
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
	for (int i = 0; i < tmp; i++) {
		tree->removeNode(arr[rand() % (this->getCount() - 1) + 0]);
	}
	timeSet->end();
	double times = timeSet->getLastTime();
	delete gen, tree, timeSet;
	return times;
}

double treeControler::deletionDegeneratedBST()
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
		bool x = tree->insertDegenerated(arr[i]);
		if (x = true) std::cout << "#" << i << ", ";
	}
	timeSet->start();
	for (int i = 0; i < tmp; i++) {
		tree->deleteValue(arr[rand() % (this->getCount() - 1) + 0]);
	}
	timeSet->end();
	double times = timeSet->getLastTime();
	delete gen, tree, timeSet;
	return times;
}

void treeControler::printBST()
{
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
	tree->inOrder()
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

void treeControler::setArray(int tab[])
{
	arr = tab;
}

void treeControler::setCount(int value)
{
	count = value;
}

int treeControler::getCount()
{
	return count;
}
