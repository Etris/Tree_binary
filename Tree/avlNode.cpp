#include "avlNode.h"
#include <iostream>

aNode * avlNode::insertBinary(aNode * tRoot, int value)
{
	if (tRoot == NULL || tRoot == nullptr) {
		aNode * wsk = new aNode;
		wsk->left = wsk->right = NULL;
		wsk->key = value;
		return wsk;
	}
	else {
		if (value < tRoot->key) tRoot->left = insertBinary(tRoot->left, value);
		else tRoot->right = insertBinary(tRoot->right, value);
		//else return tRoot; if (value >= tRoot->key)
	}
	//this->balanceTree();
}

bool avlNode::insertClassic(aNode *, int)
{
	return false;
}

aNode * avlNode::removeBin(aNode * tmp, int value)
{
	if (tmp == NULL) return tmp;
	if (value < tmp->key)
		if(tmp->left != NULL) tmp->left = removeBin(tmp->left, value);
	else if (value > tmp->key)
		if(tmp->right != NULL) tmp->right = removeBin(tmp->right, value);
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
			delete temp;
		}
		else
		{
			aNode * temp = minValueNode(tmp->right);
			tmp->key = temp->key;
			tmp->right = removeFast(tmp->right, temp->key);
		}
	}
	if (tmp == NULL) return tmp;
	this->balanceTree();
}

aNode * avlNode::removeFast(aNode * tmp, int value)
{
	if (tmp == NULL) return tmp;
	if (value < tmp->key)
		tmp->left = removeFast(tmp->left, value);
	else if (value > tmp->key)
		tmp->right = removeFast(tmp->right, value);
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
			tmp->right = removeFast(tmp->right, temp->key);
		}
	}
}

bool avlNode::removeClassic(aNode *, int)
{
	return false;
}

void avlNode::inOrder(aNode * tmp)
{
	if (tmp != NULL) {
		if (tmp->left != NULL) inOrder(tmp->left);
		std::cout << tmp->key << " ";
		if (tmp->right != NULL) inOrder(tmp->right);
	}
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
	if (tmp == NULL) return 0;
	else {
		if(tmp->left != NULL && tmp->right != NULL) return 1 + count(tmp->left) + count(tmp->right);
		else if (tmp->left != NULL && tmp->right == NULL) return 1 + count(tmp->left);
		else if (tmp->right != NULL && tmp->left == NULL) return 1 + count(tmp->right);
		else return 1;
	}
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
	tmpNode->left = buildTree(start, mid - 1);
	if(tmpNode -> left != NULL) tmpNode->left->prev = tmpNode;
	tmpNode->right = buildTree(mid + 1, end);
	if (tmpNode->right != NULL) tmpNode->right->prev = tmpNode;
	return tmpNode;
}

void avlNode::balanceTree()
{
	this->checkIfArrayIsSet();
	arr = new int[getCount()];
	var = 0;
	inOrderBuilder(root);
	std::cout << "#0.0" << std::endl;
	sortArray();
	std::cout << "#0.1" << std::endl;
	postOrderDelete(root);
	std::cout << "#0.2" << std::endl;
	buildTree(0, getCount()-1);
	std::cout << "procedure done" << std::endl;
}

void avlNode::inOrderBuilder(aNode * tmp)
{
	if (tmp != NULL && tmp != nullptr) {
		if (tmp->left != NULL) inOrderBuilder(tmp->left);
		arr[var] = tmp->key;
		var++;
		if (tmp->right != NULL) inOrderBuilder(tmp->right);
	}
}

void avlNode::postOrderDelete(aNode * tmp)
{
	if (tmp != NULL) {
		if (tmp->left != NULL) this->postOrderDelete(tmp->left);
		if (tmp->right != NULL) this->postOrderDelete(tmp->right);
		root = removeFast(root, tmp->key);
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

void avlNode::checkIfArrayIsSet()
{
	if (arr == NULL || arr[0] == NULL) {
		delete[] arr;
	}
	arr = NULL;
}

avlNode::avlNode()
{
	root = NULL;
	//arr = NULL;
	this->setCount(0);
}


avlNode::~avlNode()
{
	delete[] arr;
	while (root) {
		this->removeFast(root, this->getKey(root));
	}
}

int avlNode::getCount()
{
	//this->setCount(this->count(root));
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

void avlNode::removeTree()
{
	while (root) {
		this->postOrderDelete(root);
	}
}

void avlNode::printer()
{
	this->inOrder(root);
}

void avlNode::buildNew(int value)
{
	root = buildTree(0, value);
}

void avlNode::insertNode(int value)
{
	root = insertBinary(root, value);
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
