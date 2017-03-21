#include "avlNode.h"
#include <iostream>


aNode * avlNode::rotateLeft(aNode *)
{
	return nullptr;
}

aNode * avlNode::rotateRight(aNode *)
{
	return nullptr;
}

aNode * avlNode::rotateLR(aNode *)
{
	return nullptr;
}

aNode * avlNode::rotateRL(aNode *)
{
	return nullptr;
}

avlNode::avlNode()
{
	root = NULL;
}


avlNode::~avlNode()
{
	while (root) {
		removeNode(root);
	}
}

int avlNode::getCount()
{
	return count;
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

bool avlNode::insertNode(aNode *)
{
	
}

void avlNode::removeNode(aNode *)
{

}
