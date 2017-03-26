#pragma once
#include "numberGenerator.h"
struct aNode {
	aNode *prev, *left, *right;
	int key, balance;
};
class avlNode
{
private:
	//vars
	aNode * root;
	int counts;
	int height;
	int * arr;
	int var;
	//ins & remove
	aNode *  insertBinary(aNode *, int);
	bool insertClassic(aNode*, int);
	aNode * removeBin(aNode *, int);
	aNode * removeFast(aNode *, int);
	bool removeClassic(aNode *, int);
	//useful methods
	void inOrder(aNode *);
	aNode * minValueNode(aNode*);
	aNode * findNode(aNode *, int);
	int getKey(aNode *);
	int count(aNode *);
	bool search(aNode *, int);
	void checkIfArrayIsSet();
	// classic methods
	void rotateLeft(aNode *);
	void rotateRight(aNode *);
	void rotateLR(aNode *);
	void rotateRL(aNode *);
	//additional methods
	aNode * buildTree(int, int);
	void balanceTree();
	void inOrderBuilder(aNode*);
	void postOrderDelete(aNode *);
	void sortArray();
public:
	//constr & deconst
	avlNode();
	~avlNode();
	//settery & gettery
	int getCount();
	int getHeight();
	void setCount(int);
	void setHeight(int);
	void setArray(int[]);
	//class methods
	void removeTree();
	void printer();
	void buildNew(int);
	void insertNode(int);
	bool insertNodeClassicalMethod(int);
	void removeNode(int);
	void removeNodeClassicalMethod(int);
	bool searchKey(int);
};

