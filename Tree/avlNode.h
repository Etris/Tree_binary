#pragma once
struct aNode {
	aNode *prev, *left, *right;
	int key, bf;
};
class avlNode
{
private:
	aNode * root;
	int count;
	int height;
	aNode * rotateLeft(aNode *);
	aNode * rotateRight(aNode *);
	aNode * rotateLR(aNode *);
	aNode * rotateRL(aNode *);
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
	
};

