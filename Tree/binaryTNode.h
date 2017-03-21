#pragma once
struct Node {
	Node * prev, *left, *right;
	int key;
};
class binaryTNode
{
private:
	Node * root;
	int count;
	int height;
	void levelOrderSetCurrentLevel(int);
public:
	//constructor & dec
	binaryTNode();
	~binaryTNode();
	//settery & gettery
	int getCount();
	int getHeight();
	int getHeightOfNode(Node *);
	void setCount(int);
	void setHeight(int);
	//class methods
	bool insertNode(Node *);
	Node * search(Node*, int);
	int maxKey(Node *);
	int minKey(Node *);
	Node * maxNode(Node *);
	Node * minNode(Node *);
	Node * prev(Node *);
	Node * succ(Node *);
	Node * remove(Node*);
	void preOrder(Node*);
	void inOrder(Node*);
	void postOrder(Node*);
	void levelOrder(Node*);
	void walk(Node *);
	void countBST();
};

