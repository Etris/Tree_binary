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
	this->balanceTree(root);
	return true;
}

bool avlNode::insertClassic(aNode *, int)
{
	return false;
}

aNode * avlNode::removeBin(aNode * tmp, int value)
{
	if (root == NULL) return root;
	if (value < tmp->key)
		tmp->left = removeBin(tmp->left, value);
	else if (value > tmp->key)
		tmp->right = removeBin(tmp->right, value);
	else
	{
		if ((tmp->left == NULL) || (tmp->right == NULL))
		{
			aNode * temp = NULL;
			if (temp == tmp->left)
				temp = tmp->right;
			else
				temp = tmp->left;
			if (temp == NULL)
			{
				temp = tmp;
				tmp = NULL;
			}
			else 
				tmp = temp; 
		}
		else
		{
			aNode * temp = minValueNode(tmp->right);
			tmp->key = temp->key;
			tmp->right = removeBin(tmp->right, temp->key);
		}
	}
	this->balanceTree(root);
}

bool avlNode::removeClassic(aNode *, int)
{
	return false;
}

aNode * avlNode::minValueNode(aNode * node)
{
		aNode * current = node;
		while (current->left != NULL)
			current = current->left;
		return current;
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

aNode * avlNode::buildTree(int start, int end)
{
	if (start > end) {
		return NULL;
	}
	int mid = (start + end) / 2;
	aNode * tmpNode = new aNode;
	tmpNode->key = arr[mid];
	tmpNode->left = this->buildTree(start, mid - 1);
	tmpNode->left->prev = tmpNode;
	tmpNode->right = this->buildTree(mid + 1, end);
	tmpNode->right->prev = tmpNode;
	return tmpNode;
}

void avlNode::balanceTree(aNode * tmp)
{
	if (arr != NULL)
	{
		delete[] arr;
		arr = NULL;
	}
	arr = new int[getCount()];
	this->inOrderBuilder(root, 0);
	this->sortArray();
	this->postOrderDelete(root);
	buildTree(0, this->getCount());
}

void avlNode::inOrderBuilder(aNode * tmp, int var)
{
	if (tmp != NULL) {
		if (tmp->left != NULL) inOrderBuilder(tmp->left, var + 1);
		std::cout << tmp->key;
		arr[var] = tmp->key;
		if (tmp->right != NULL) inOrderBuilder(tmp->right, var + 2);
	}
}

void avlNode::postOrderDelete(aNode * tmp)
{
	if (tmp != NULL) {
		if (tmp->left != NULL) this->postOrderDelete(tmp->left);
		if (tmp->right != NULL) this->postOrderDelete(tmp->right);
		this->removeBin(tmp, this->getKey(tmp));
	}
}

void avlNode::sortArray()
{
	int tmp, i, j, x;
	for (tmp = 1; tmp <= getCount() / 3; tmp = 3 * tmp + 1) {}
	while (tmp > 0) {
		for (int i = getCount() - tmp - 1; i >= 0; i--) {
			x = arr[i];
			j = i + tmp;
			while ((j < getCount()) && (x > arr[j])) {
				arr[j - tmp] = arr[j];
				j = j + tmp;
			}
			arr[j - tmp] = x;
		}
		tmp /= 3;
	}
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
	counts = value;
}

void avlNode::setHeight(int value)
{
	height = value;
}

void avlNode::setArray(int tab[])
{
	arr = new int[getCount()];
	arr = tab;
}

void avlNode::buildNew(int value)
{
	root = buildTree(0, value);
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
