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
	Node * remove(Node *, int);
	Node * createNode(Node*, int);
	Node * search(Node*, int);
	bool searcher(Node * tmp, int value);
	void preOrder(Node*);
	void inOrder(Node*);
	void postOrder(Node*);
	void levelOrder(Node*);
	void postOrderDelete(Node *);
public:
	//constructor & dec
	binaryTNode();
	~binaryTNode();
	//settery & gettery
	void setNullRoot();
	int getCount();
	int getHeight();
	void setCount(int);
	void setHeight(int);
	//class methods
	bool find(int);
	int maxDepth(Node *);
	void insertNode(int);
	int maxKey(Node *);
	int minKey(Node *);
	Node * maxNode(Node *);
	Node * minNode(Node *);
	Node * prev(Node *);
	Node * succ(Node *);
	void deleteValue(int);
	void printer();
	int countBST(Node *);
	void removeTree();
};

