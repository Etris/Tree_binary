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
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteArray();
	binaryTNode * tree = new binaryTNode;
	timer * timeSet = new timer;
	arr = gen->getCopyOfArray();
	tree->setNullRoot();
	timeSet->start();
	for (int i = 0; i < this->getCount(); i++) {
		tree->insertNode(arr[i]);
		//if (x = true) std::cout << "#" << i << ", ";
	}
	timeSet->end();
	double times = timeSet->getLastTime();
	delete gen, tree, timeSet;
	return times;
}

double treeControler::buildAVL()
{
	numberGenerator * gen = new numberGenerator;
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteSortedArray();
	avNodes * tree = new avNodes;
	timer * timeSet = new timer;
	tree->setArray(gen->getCopyOfArray());
	tree->setNumbers(this->getCount());
	timeSet->start();
	tree->buildNewTree(this->getCount()-1);
	timeSet->end();
	double times = timeSet -> getLastTime();
	delete gen, tree, timeSet;
	return times;
}

double treeControler::buildDegeneratedBST()
{
	numberGenerator * gen = new numberGenerator;
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteSortedArray();
	binaryTNode * tree = new binaryTNode;
	timer * timeSet = new timer;
	arr = gen->getCopyOfArray();
	timeSet->start();
	for (int i = 0; i < this->getCount(); i++) {
		tree->insertNode(arr[i]);
		//if (x = true) std::cout << "#" << i << ", ";
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
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteArray();
	binaryTNode * tree = new binaryTNode;
	timer * timeSet = new timer;
	arr = gen->getCopyOfArray();
	for (int i = 0; i < this->getCount(); i++) {
		tree->insertNode(arr[i]);
		//if (x = true) std::cout << "#" << i << ", ";
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
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteSortedArray();
	avNodes * tree = new avNodes;
	timer * timeSet = new timer;
	tree->setArray(gen->getCopyOfArray());
	tree->buildNewTree(this->getCount());
	timeSet->start();
	for (int a = 0; a < tmp; a++) {
		int abs = rand() % (200000 - 1) + 0;
		bool c = tree->searchValue(abs);
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
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteSortedArray();
	binaryTNode * tree = new binaryTNode;
	timer * timeSet = new timer;
	arr = gen->getCopyOfArray();
	for (int i = 0; i < this->getCount(); i++) {
		tree->insertNode(arr[i]);
		//if (x = true) std::cout << "#" << i << ", ";
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
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteArray();
	binaryTNode * tree = new binaryTNode;
	timer * timeSet = new timer;
	arr = gen->getCopyOfArray();
	for (int i = 0; i < this->getCount(); i++) {
		tree->insertNode(arr[i]);
		//if (x = true) std::cout << "#" << i << ", ";
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
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteSortedArray();
	timer * timeSet = new timer;
	avNodes * tree = new avNodes;
	timeSet->start();
	std::cout << tmp << std::endl;
	arr = gen->getCopyOfArray();
	tree->setArray(arr);
	tree->buildNewTree(this->getCount()-1);
	std::cout << "builded" << std::endl;
	for (int i = 0; i < tmp; i++) {
		tree->setNumbers(gen->getNumbers() + 1 + i);
		std::cout << "setted" << std::endl;
		tree->addElement(arr[this->getCount() - 1 - i]);
		std::cout << "mProcedure done" << std::endl;
	}
	delete tree;
	timeSet->end();
	double times = timeSet->getLastTime();
	return times;
}

double treeControler::insertionDegeneratedBST()
{
	int tmp = this->getCount() / 10;
	numberGenerator * gen = new numberGenerator;
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteSortedArray();
	binaryTNode * tree = new binaryTNode;
	timer * timeSet = new timer;
	arr = gen->getCopyOfArray();
	for (int i = 0; i < this->getCount(); i++) {
		tree->insertNode(arr[i]);
		//if (x = true) std::cout << "#" << i << ", ";
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

double treeControler::deletionBST()
{
	int tmp = this->getCount() / 10;
	srand(time(nullptr));
	numberGenerator * gen = new numberGenerator;
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteArray();
	binaryTNode * tree = new binaryTNode;
	timer * timeSet = new timer;
	arr = gen->getCopyOfArray();
	for (int i = 0; i < this->getCount(); i++) {
		tree->insertNode(arr[i]);
		//std::cout << "#" << i << ", ";
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
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteSortedArray();
	avNodes * tree = new avNodes;
	timer * timeSet = new timer;
	tree->setArray(gen->getCopyOfArray());
	arr = gen->getCopyOfArray();
	tree->buildNewTree(this->getCount()-1);
	timeSet->start();
	for (int i = 0; i < tmp; i++) {
		tree->setNumbers(gen->getNumbers() - i);
		//std::cout << "setted" << std::endl;
		tree->removeElement(arr[count-20-i]);
		tree->balanceTree();
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
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteSortedArray();
	binaryTNode * tree = new binaryTNode;
	timer * timeSet = new timer;
	arr = gen->getCopyOfArray();
	for (int i = 0; i < this->getCount(); i++) {
		 tree->insertNode(arr[i]);
		//if (x = true) std::cout << "#" << i << ", ";
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
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteArray();
	binaryTNode * tree = new binaryTNode;
	arr = gen->getCopyOfArray();
	tree->setNullRoot();
	for (int i = 0; i < this->getCount(); i++) {
		tree->insertNode(arr[i]);
		//if (x = true) std::cout << "#" << i << ", ";
	}
	tree->printer();
	delete gen, tree;
}

void treeControler::printAVL()
{
	numberGenerator * gen = new numberGenerator;
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteSortedArray();
	avNodes * tree = new avNodes;
	tree->setArray(gen->getCopyOfArray());
	tree->buildNewTree(this->getCount()-1);
	tree->inOrder();
	delete gen, tree;
}

void treeControler::printDBST()
{
	numberGenerator * gen = new numberGenerator;
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteSortedArray();
	binaryTNode * tree = new binaryTNode;
	arr = gen->getCopyOfArray();
	for (int i = 0; i < this->getCount(); i++) {
		tree->insertNode(arr[i]);
		//if (x = true) std::cout << "#" << i << ", ";
	}
	tree->printer();
	delete gen, tree;
}

void treeControler::removeBST()
{
	numberGenerator * gen = new numberGenerator;
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteArray();
	binaryTNode * tree = new binaryTNode;
	arr = gen->getCopyOfArray();
	tree->setNullRoot();
	for (int i = 0; i < this->getCount(); i++) {
		tree->insertNode(arr[i]);
		//if (x = true) std::cout << "#" << i << ", ";
	}
	tree->removeTree();
	delete gen, tree;
}

void treeControler::removeAVL()
{
	numberGenerator * gen = new numberGenerator;
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteSortedArray();
	avNodes * tree = new avNodes;
	tree->setArray(gen->getCopyOfArray());
	tree->buildNewTree(this->getCount());
	tree->removeTree();
	delete gen, tree;
}

void treeControler::removeDBST()
{
	numberGenerator * gen = new numberGenerator;
	gen->setMin(0);
	gen->setMax(200000);
	gen->setNumbers(this->getCount());
	gen->genereteSortedArray();
	binaryTNode * tree = new binaryTNode;
	arr = gen->getCopyOfArray();
	for (int i = 0; i < this->getCount(); i++) {
		tree->insertNode(arr[i]);
		//if (x = true) std::cout << "#" << i << ", ";
	}
	tree->removeTree();
	delete gen, tree;
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
