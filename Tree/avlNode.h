#pragma once
struct aNode {
	aNode *prev, *left, *right;
	int key, balance;
};
class avlNode
{
private:
	aNode * root;
	int counts;
	int height;
	bool insertBinary(aNode *, int);
	bool insertClassic(aNode*, int);
	bool removeBin(aNode *, int);
	bool removeClassic(aNode *, int);
	aNode * findNode(aNode *, int);
	int getKey(aNode *);
	int count(aNode *);
	void  rotateLeft(aNode *);
	void rotateRight(aNode *);
	void rotateLR(aNode *);
	void rotateRL(aNode *);
	bool search(aNode *, int);
public:
	//constr & deconst
	avlNode();
	~avlNode();
	//settery & gettery
	int getCount();
	int getHeight();
	void setCount(int);
	void setHeight(int);
	//class methods
	bool insertNode(int);
	bool insertNodeClassicalMethod(int);
	void removeNode(int);
	void removeNodeClassicalMethod(int);
	bool searchKey(int);
};

