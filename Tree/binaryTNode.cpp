#include "binaryTNode.h"
#include <iostream>
#include <stack>

void binaryTNode::levelOrderSetCurrentLevel(Node * tmp, int level)
{
	if (tmp == NULL) {
		return;
	}
	if (level == 1) {
		std::cout << tmp->key;
	}
	else {
		this->levelOrderSetCurrentLevel(tmp->left, level - 1);
		this->levelOrderSetCurrentLevel(tmp->right, level - 1);
	}
}

binaryTNode::binaryTNode()
{
	root = NULL;
	setCount(0);
}


binaryTNode::~binaryTNode()
{
	while (root) {
		this->remove(root, root->key);
		//delete root;
	}
}

void binaryTNode::setNullRoot()
{
	root = NULL;
}

int binaryTNode::getCount()
{
	return count;
}

int binaryTNode::getHeight()
{
	return height;
}

int binaryTNode::getHeightOfNode(Node * tmp)
{
	if (root == NULL) {
		return 0;
	}
	else {
		int leftHeight = this->getHeightOfNode(tmp->left);
		int rightHeight = this->getHeightOfNode(tmp->right);
		if (leftHeight > rightHeight) {
			return leftHeight + 1;
		}
		else {
			return rightHeight + 1;
		}
	}
}

Node * binaryTNode::remove(Node * tmp, int value)
{
	if (tmp == NULL) {
		return tmp;
	}
	else {
		if (value < tmp->key) if(tmp->left != NULL) tmp->left = remove(tmp->left, value);
		if (value > tmp->key)if (tmp->right != NULL) tmp->right = remove(tmp->right, value);
		else {
			if (tmp->left == NULL) {
				Node * temp = tmp->right;
				delete tmp;
				return temp;
			}
			else if (tmp->right == NULL) {
				Node * temp = tmp->left;
				delete tmp;
				return temp;
			}
			Node * temp = minNode(tmp->right);
			tmp->key = temp->key;
			tmp->right = remove(tmp->right, temp->key);
		}
		return tmp;
	}
}


void binaryTNode::setCount(int value)
{
	count = value;
}

void binaryTNode::setHeight(int value)
{
	height = value;
}

bool binaryTNode::find(int value)
{
	if (this->searcher(root, value) == true) return true;
	else return false;
}

int binaryTNode::maxDepth(Node * tmp)
{
	if (tmp == NULL) {
		return 0;
	}else{
		int leftDepth = this->maxDepth(tmp->left);
		int rightDepth = this->maxDepth(tmp->right);
		if (leftDepth > rightDepth) {
			return leftDepth + 1;
		}
		else {
			return rightDepth + 1;
		}
	}
}

Node * binaryTNode::createNode(Node * tmp, int value)
{
	if (tmp == NULL) {
		tmp = new Node;
		tmp->key = value;
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->prev = NULL;
		return tmp;
	}
	else {
		if (value < tmp->key) {
			tmp->left = this->createNode(tmp->left, value);
		}
		else {
			tmp->right = this->createNode(tmp->right, value);
		}
	}
	return tmp;
}

void binaryTNode::insertNode(int value)
{
	root = this->createNode(root, value);
}

/*
Procedura iteracyjna:
while(tmp != NULL && tmp->key != value){
	if(value < tmp->key){
		tmp = tmp->left;
	}
	else{
		tmp = tmp->right;
	}
}
*/
Node * binaryTNode::search(Node * tmp, int value)
{
	if (tmp->key == value) {
		return tmp;
	}
	else {
		if (value < tmp->key) {
			if(tmp->left != NULL) this->search(tmp->left, value);
		}
		else {
			if(tmp->right != NULL) this->search(tmp->right, value);
		}
	}
}
bool binaryTNode::searcher(Node * tmp, int value)
{
	if (tmp->key == value) {
		return true;
	}
	else {
		if (value < tmp->key) {
			if (tmp->left != NULL) this->search(tmp->left, value);
		}
		else {
			if (tmp->right != NULL) this->search(tmp->right, value);
		}
	}
}

int binaryTNode::maxKey(Node * tmp)
{
	while (tmp->right != NULL) {
		tmp = tmp->right;
	}
	return tmp->key;
}

int binaryTNode::minKey(Node * tmp)
{
	while (tmp->left != NULL) {
		tmp = tmp->left;
	}
	return tmp->key;
}

Node * binaryTNode::maxNode(Node * tmp)
{
	while (tmp->right != NULL) {
		tmp = tmp->right;
	}
	return tmp;
}

Node * binaryTNode::minNode(Node * tmp)
{
	while (tmp->left != NULL) {
		tmp = tmp->left;
	}
	return tmp;
}

Node * binaryTNode::prev(Node * tmp)
{
	return tmp->prev;
}

Node * binaryTNode::succ(Node * tmp)
{
	return tmp->right;
}

void binaryTNode::deleteValue(int value)
{
	this->remove(root, value);
}


void binaryTNode::preOrder(Node * tmp)
{
	//Stack include implementation:
	/*
	std::stack<Node*> tmpStack;
	tmpStack.push(tmp);
	while (tmpStack.empty() == false) {
		tmp = tmpStack.top();
		tmpStack.pop();
		std::cout << tmp->key;
		if (tmp->left != NULL) tmpStack.push(tmp->left);
		if (tmp->right != NULL) tmpStack.push(tmp->right);
	}
	*/
	if (tmp != NULL) {
		std::cout << tmp->key;
		if (tmp->left != NULL) preOrder(tmp->left);
		if (tmp->right != NULL) preOrder(tmp->right);
	}
}

void binaryTNode::inOrder(Node * tmp)
{
	if (tmp != NULL) {	
		if(tmp->left != NULL) inOrder(tmp->left);
		std::cout << tmp->key << " ";
		if(tmp->right != NULL) inOrder(tmp->right);
	}
}

void binaryTNode::postOrder(Node * tmp)
{
	if (tmp != NULL) {
		if (tmp->left != NULL) this->postOrder(tmp->left);
		if (tmp->right != NULL) this->postOrder(tmp->right);
		std::cout << tmp->key;
	}
}

void binaryTNode::levelOrder(Node * tmp)
{
	int hTemporary = getHeightOfNode(this->root);
	for (int i = 1; i <= hTemporary; i++) {
		this->levelOrderSetCurrentLevel(tmp, i);
	}
}

void binaryTNode::printer()
{
	this->inOrder(root);
}

int binaryTNode::countBST(Node * tmp)
{
	if (root != 0) return 0;
	else return 1 + countBST(root->left) + countBST(root->right);
}

void binaryTNode::postOrderDelete(Node * tmp)
{
	if (tmp != NULL) {
		if (tmp->left != NULL) this->postOrderDelete(tmp->left);
		if (tmp->right != NULL) this->postOrderDelete(tmp->right);
		remove(root, tmp->key);
	}
	root = NULL;
}

void binaryTNode::removeTree()
{
	this->postOrderDelete(root);
}
