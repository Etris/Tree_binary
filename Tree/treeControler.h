#pragma once
#include "binaryTNode.h"
#include "avlNode.h"
#include "avNodes.h"
#include "numberGenerator.h"
#include "timer.h"
class treeControler
{
private:
	int *arr;
	int count;
public:
	//const & deconst
	treeControler();
	~treeControler();
	//constructors:
	double buildBST();
	double buildAVL();
	double buildDegeneratedBST();
	//methods:
	// n/10 elements finder
	double finderBST();
	double finderAVL();
	double finderDegeneratedBST();
	// n/10 element insertion
	double insertionBST();
	double insertionAVL();
	double insertionDegeneratedBST();
	// n/10 element deletion
	double deletionBST();
	double deletionAVL();
	double deletionDegeneratedBST();
	//sortedOrder print:
	void printBST();
	void printAVL();
	void printDBST();
	//structure removers
	void removeBST();
	void removeAVL();
	void removeDBST();
	//settery i gettery
	void setArray(int[]);
	void setCount(int);
	int getCount();
};

