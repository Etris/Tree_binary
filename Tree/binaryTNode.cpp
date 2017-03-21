#include "binaryTNode.h"
#include <iostream>
#include <stack>

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
	return false;
}

Node * binaryTNode::search(int value)
{
	return nullptr;
}

int binaryTNode::maxKey(Node *)
{
	return 0;
}

int binaryTNode::minKey(Node *)
{
	return 0;
}

Node * binaryTNode::maxNode(Node *)
{
	return nullptr;
}

Node * binaryTNode::minNode(Node *)
{
	return nullptr;
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
