#pragma once
#include <iostream>
struct avlTreeNode {
	int key;
	avlTreeNode * left, *right, *prev;
};
class avNodes
{
private:
	avlTreeNode * root;
	int * arr;
	int numbers;
	int var;
	avlTreeNode * insertNode(avlTreeNode *, int);
	avlTreeNode * deleteNode(avlTreeNode *, int);
	avlTreeNode * deleteNodeWithoutBalance(avlTreeNode*, int);
	avlTreeNode * minValue(avlTreeNode *);
	avlTreeNode * buildTree(int, int);
	void inOrderPrinter(avlTreeNode *);
	void inOrderBuilder(avlTreeNode *);
	void postOrderDelete(avlTreeNode *);
	void sortArray();
	bool find(avlTreeNode *, int);
public:
	//
	avNodes();
	~avNodes();
	//
	void addElement(int);
	void removeElement(int);
	void inOrder();
	void buildNewTree(int);
	bool searchValue(int);
	void removeTree();
	void balanceTree();
	//
	void setNumbers(int);
	void setArray(int[]);
	int getNumbers();
};

