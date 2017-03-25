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
	void levelOrderSetCurrentLevel(Node*, int);
	int getHeightOfNode(Node *);
	bool remove(Node*, Node *, int);
	void createNode(Node*, int);
	void createDegeNode(Node *, int);
	Node * search(Node*, int);
	bool searcher(Node * tmp, int value);
public:
	//constructor & dec
	binaryTNode();
	~binaryTNode();
	//settery & gettery
	int getCount();
	int getHeight();
	void setCount(int);
	void setHeight(int);
	//class methods
	bool find(int);
	int maxDepth(Node *);
	bool insertNode(int);
	bool insertDegenerated(int);
	int maxKey(Node *);
	int minKey(Node *);
	Node * maxNode(Node *);
	Node * minNode(Node *);
	Node * prev(Node *);
	Node * succ(Node *);
	void deleteValue(int);
	void preOrder(Node*);
	void inOrder(Node*);
	void postOrder(Node*);
	void levelOrder(Node*);
	void printer();
	void walk(Node *);
	int countBST(Node *);
};

