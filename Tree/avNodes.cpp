#include "avNodes.h"

avNodes::avNodes()
{
	root = NULL;
	arr = NULL;
}

avNodes::~avNodes()
{
	delete[] arr;
	arr = NULL;
	delete root;
}

void avNodes::addElement(int value)
{
	root = insertNode(root, value);
}

void avNodes::removeElement(int value)
{
	root = this->deleteNodeWithoutBalance(root, value);
}

void avNodes::inOrder()
{
	this->inOrderPrinter(root);
}

void avNodes::buildNewTree(int value)
{
	this->setNumbers(value);
	root = buildTree(0, value);
}

bool avNodes::searchValue(int value)
{
	if (find(root, value) == true) return true;
	else return false;
}

void avNodes::removeTree()
{
	this->postOrderDelete(root);
}

void avNodes::setNumbers(int value)
{
	numbers = value;
}

void avNodes::setArray(int tab[])
{
	arr = tab;
}

int avNodes::getNumbers()
{
	return numbers;
}

avlTreeNode * avNodes::insertNode(avlTreeNode * tmp, int value)
{
	if (this->find(root, value) == true) return tmp;
	else {
		if (tmp == NULL) {
			avlTreeNode * wsk = new avlTreeNode;
			wsk->left = wsk->right = NULL;
			wsk->key = value;
			return wsk;
		}
		else {
			if (value < tmp->key) tmp->left = insertNode(tmp->left, value);
			else if (value > tmp->key) tmp->right = insertNode(tmp->right, value);
			else if (value == tmp->key) return tmp;
			else return tmp;
		}
		//this->balanceTree();
	}
}

avlTreeNode * avNodes::deleteNode(avlTreeNode * tmp, int value)
{
	if (tmp == NULL) return tmp;
	if (value < tmp->key)
		if (tmp->left != NULL) tmp->left = deleteNode(tmp->left, value);
		else if (value > tmp->key)
			if (tmp->right != NULL) tmp->right = deleteNode(tmp->right, value);
			else
			{
				if ((tmp->left == NULL) || (tmp->right == NULL))
				{
					avlTreeNode * temp = new avlTreeNode;
					temp = NULL;
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
					avlTreeNode * temp = new avlTreeNode;
					temp = minValue(tmp->right);
					tmp->key = temp->key;
					tmp->right = deleteNodeWithoutBalance(tmp->right, temp->key);
				}
			}
	if (tmp == NULL) return tmp;
	numbers--;
	//this->balanceTree();
}

avlTreeNode * avNodes::deleteNodeWithoutBalance(avlTreeNode * tmp, int value)
{
	if (tmp == NULL) return tmp;
	if (value < tmp->key)
		if (tmp->left != NULL) tmp->left = deleteNodeWithoutBalance(tmp->left, value);
		else if (value > tmp->key)
			if (tmp->right != NULL) tmp->right = deleteNodeWithoutBalance(tmp->right, value);
			else
			{
				if ((tmp->left == NULL) || (tmp->right == NULL))
				{
					avlTreeNode * temp = new avlTreeNode;
					temp = NULL;
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
					avlTreeNode * temp = new avlTreeNode;
					temp = minValue(tmp->right);
					tmp->key = temp->key;
					tmp->right = deleteNodeWithoutBalance(tmp->right, temp->key);
				}
			}
	if (tmp == NULL) return tmp;
}

avlTreeNode * avNodes::minValue(avlTreeNode * tmp)
{
	avlTreeNode * current = new avlTreeNode;
	current = tmp;
	while (current->left != NULL)
		current = current->left;
	return current;
}

avlTreeNode * avNodes::buildTree(int start, int end)
{
	if (start >= end) {
		return NULL;
	}
	int mid = (start + end) / 2;
	avlTreeNode * tmpNode = new avlTreeNode;
	tmpNode->key = arr[mid];
	tmpNode->left = buildTree(start, mid - 1);
	if (tmpNode->left != NULL) tmpNode->left->prev = tmpNode;
	tmpNode->right = buildTree(mid + 1, end);
	if (tmpNode->right != NULL) tmpNode->right->prev = tmpNode;
	return tmpNode;
}

void avNodes::inOrderPrinter(avlTreeNode * tmp)
{
	if (tmp != NULL && tmp != nullptr) {
		if (tmp->left != NULL) inOrderPrinter(tmp->left);
		std::cout << tmp->key << " ";
		if (tmp->right != NULL) inOrderPrinter(tmp->right);
	}
}

void avNodes::balanceTree()
{
	arr = new int[numbers];
	var = 0;
	inOrderBuilder(root);
	std::cout << "#0.0" << std::endl;
	sortArray();
	std::cout << "#0.1" << std::endl;
	postOrderDelete(root);
	std::cout << "#0.2" << std::endl;
	buildTree(0, var);
	std::cout << "procedure done" << std::endl;
	numbers = numbers - 1;
}

void avNodes::inOrderBuilder(avlTreeNode * tmp)
{
	if (tmp != NULL) {
		if (tmp->left != NULL) inOrderBuilder(tmp->left);
		if(tmp->key != NULL) arr[var++] = tmp->key;
		if (tmp->right != NULL) inOrderBuilder(tmp->right);
	}
}

void avNodes::postOrderDelete(avlTreeNode * tmp)
{
	if (tmp != NULL) {
		if (tmp->left != NULL) this->postOrderDelete(tmp->left);
		if (tmp->right != NULL) this->postOrderDelete(tmp->right);
		deleteNodeWithoutBalance(root, tmp->key);
	}
	root = NULL;
}

void avNodes::sortArray()
{
	int tmp, i, j, x;
	for (tmp = 1; tmp <= getNumbers() / 3; tmp = 3 * tmp + 1) {}
	while (tmp > 0) {
		for (int i = getNumbers() - tmp - 1; i >= 0; i--) {
			x = arr[i];
			j = i + tmp;
			while ((j < getNumbers()) && (x > arr[j])) {
				arr[j - tmp] = arr[j];
				j = j + tmp;
			}
			arr[j - tmp] = x;
		}
		tmp /= 3;
	}
}

bool avNodes::find(avlTreeNode * tmp, int value)
{
	if (tmp->key == value) {
		return true;
	}
	else {
		if (value < tmp->key) {
			if (tmp->left != NULL) this->find(tmp->left, value);
		}
		else {
			if (tmp->right != NULL) this->find(tmp->right, value);
		}
	}
}
