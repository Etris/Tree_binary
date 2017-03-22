#include "avlNode.h"
#include <iostream>


bool avlNode::insertBinary(aNode * tRoot, int value)
{
	aNode * wsk, *ptr, *tmp;
	bool t;
	wsk = new aNode;
	wsk->left = wsk->right = wsk->prev = NULL;
	wsk->key = value;
	wsk->balance = 0;
	ptr = tRoot;
	if (ptr == NULL) root = wsk;
	else {
		while (true) {
			if (value < ptr->key) {
				if (ptr->left != NULL) {
					ptr->left = wsk;
					break;
				}
				else {
					ptr = ptr->left;
				}
			}
			else {
				if (ptr->right != NULL) {
					ptr->right = wsk;
					break;
				}
				else {
					ptr = ptr->right;
				}
			}
		}
		wsk->prev = ptr;
	}

}

bool avlNode::insertClassic(aNode *, int)
{
	return false;
}

bool avlNode::removeBin(aNode *, int)
{
	return false;
}

bool avlNode::removeClassic(aNode *, int)
{
	return false;
}

aNode * avlNode::findNode(aNode * tmp, int value)
{
	if (tmp->key == value) {
		return tmp;
	}
	else {
		if (value < tmp->key) {
			if (tmp->left != NULL) this->findNode(tmp->left, value);
		}
		else {
			if (tmp->right != NULL) this->findNode(tmp->right, value);
		}
	}
}

int avlNode::getKey(aNode * tmp)
{
	return tmp->key;
}

int avlNode::count(aNode * tmp)
{
	if (root != 0) return 0;
	else return 1 + count(root->left) + count(root->right);
}


void avlNode::rotateLeft(aNode *)
{
	
}

void avlNode::rotateRight(aNode *)
{

}

void avlNode::rotateLR(aNode *)
{
	
}

void avlNode::rotateRL(aNode *)
{
	
}

bool avlNode::search(aNode * tmp, int value)
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

avlNode::avlNode()
{
	root = NULL;
}


avlNode::~avlNode()
{
	while (root) {
		this->removeBin(root, this->getKey(root));
	}
}

int avlNode::getCount()
{
	this->setCount(this->count(root));
	return counts;
}

int avlNode::getHeight()
{
	return height;
}

void avlNode::setCount(int value)
{
	count = value;
}

void avlNode::setHeight(int value)
{
	height = value;
}

bool avlNode::insertNode(int value)
{
	if (this->insertBinary(root, value) == true) return true;
	else return false;
}

bool avlNode::insertNodeClassicalMethod(int value)
{
	if (this->insertClassic(root, value) == true) return true;
	else return false;
}

void avlNode::removeNode(int value)
{
	this->removeBin(root, value);
}

void avlNode::removeNodeClassicalMethod(int value)
{
	this->removeClassic(root, value);
}

bool avlNode::searchKey(int value)
{
	if (this->search(root, value) == true) return true;
	else return false;
}
