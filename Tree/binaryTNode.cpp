#include "binaryTNode.h"
#include <iostream>
#include <stack>

void binaryTNode::levelOrderSetCurrentLevel(int tmp)
{

}

binaryTNode::binaryTNode()
{
	root = NULL;
	setCount(0);
}


binaryTNode::~binaryTNode()
{
	while (root) {
		this->remove(root);
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

void binaryTNode::setCount(int value)
{
	count = value;
}

void binaryTNode::setHeight(int value)
{
	height = value;
}

bool binaryTNode::insertNode(Node * tmp)
{
		
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

Node * binaryTNode::prev(Node *)
{
	return nullptr;
}

Node * binaryTNode::succ(Node *)
{
	return nullptr;
}

Node * binaryTNode::remove(Node *)
{
	return nullptr;
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
	
}

void binaryTNode::walk(Node *)
{

}

void binaryTNode::countBST()
{

}
