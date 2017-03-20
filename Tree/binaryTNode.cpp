#include "binaryTNode.h"
#include <iostream>


binaryTNode::binaryTNode()
{
	root = NULL;
	setCount(0);
}


binaryTNode::~binaryTNode()
{
	while (root) {
		this->remove(root);
		delete root;
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

void binaryTNode::setCount(int value)
{
	count = value;
}

void binaryTNode::setHeight(int value)
{
	height = value;
}

bool binaryTNode::insertNode(Node *)
{
	return false;
}

Node * binaryTNode::search(int)
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

void binaryTNode::preOrder(Node *)
{
}

void binaryTNode::inOrder(Node *)
{
}

void binaryTNode::postOrder(Node *)
{
}

void binaryTNode::levelOrder(Node *)
{
}

void binaryTNode::walk(Node *)
{
}

void binaryTNode::countBST()
{
}
