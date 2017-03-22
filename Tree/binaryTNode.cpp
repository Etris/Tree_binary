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
		this->remove(NULL, root, root->key);
		//delete root;
	}
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

bool binaryTNode::remove(Node * parent, Node * current, int value)
{
	if (current == NULL) return false;
	if (current->key == value) {
		if (current->left == NULL || current->right == NULL) {
			Node * temp = current->left;
			if (current->right) temp = current->right;
			if (parent) {
				if (parent->left == current) {
					parent->left = temp;
				}
				else {
					parent->right = temp;
				}
			}
			else {
				this->root = temp;
			}
		}
		else {
			Node * validSubs = current->right;
			while (validSubs->left) {
				validSubs = validSubs->left;
			}
			int temp = current->key;
			current->key = validSubs->key;
			validSubs->key = temp;
			return remove(current, current->right, temp);
		}
		delete current;
		return true;
	}
	return remove(current, current->left, value) || remove(current, current->right, value);
}


void binaryTNode::setCount(int value)
{
	count = value;
}

void binaryTNode::setHeight(int value)
{
	height = value;
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

void binaryTNode::createNode(Node * tmp,int value)
{
	if (tmp->key > value) {
		if (tmp->left != NULL) {
			tmp->left = new Node;
		}
		else {
			createNode(tmp->left, value);
		}
	}
	else {
		if (tmp->right != NULL) {
			tmp->right = new Node;
			tmp->right->key = value;
			tmp->right->left = NULL;
			tmp->right->right = NULL;
			tmp->right->prev = tmp;
		}
		else {
			createNode(tmp->right, value);
		}
	}

}

bool binaryTNode::insertNode(int value)
{
	if (root == NULL) {
		root = new Node;
		root->key = value;
		root->left = NULL;
		root->right = NULL;
		root->prev = NULL;
	}
	else {
		createNode(root, value);
	}
	return true;
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
	this->remove(this->prev(this->search(root, value)), this->search(root, value), value);
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
		std::cout << tmp->key;
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

void binaryTNode::walk(Node *)
{

}

int binaryTNode::countBST(Node * tmp)
{
	if (root != 0) return 0;
	else return 1 + countBST(root->left) + countBST(root->right);
}
