#include "numberGenerator.h"
#include <iostream>
#include <time.h>

int numberGenerator::randNumber()
{
	return rand() % (getMaximumValue() - getMinimumValue()) + getMinimumValue();
}

void numberGenerator::makeMainArray()
{
	this->nullArray();
	srand(time(nullptr));
	for (int i = 0; i < getNumbers(); i++) {
		this->getUnique(i);
	}
}

void numberGenerator::checkIfArrayExsist()
{
	if (arr != NULL)
	{
		delete[] arr;
		arr = NULL;
	}
}

void numberGenerator::checkIfCopyExsist()
{
	if (tab != NULL)
	{
		delete[] tab;
		tab = NULL;
	}
}

void numberGenerator::setNullArray()
{
	arr = NULL;
}

void numberGenerator::setNullCopy()
{
	tab = NULL;
}

void numberGenerator::nullArray()
{
	for (int i = 0; i < getNumbers(); i++) {
		arr[i] = 0;
	}
}

void numberGenerator::getUnique(int i)
{
	int tmp = this->randNumber();
	if (this->isInArray(i, tmp) == true) {
		getUnique(i);
	}
	else {
		arr[i] = tmp;
	}
}

bool numberGenerator::isInArray(int i, int tmp)
{
	int state;
	for (int x = 0; x < i; x++) {
		if (arr[x] == tmp) {
			state = true;
			break;
		}
		else {
			state = false;
		}
	}
	return state;
}

numberGenerator::numberGenerator()
{
	this->setNullArray();
	this->setNullCopy();
	this->setNumbers(0);
	this->setMin(0);
	this->setMax(0);
}


numberGenerator::~numberGenerator()
{
	delete[] arr;
	delete[] tab;
}

void numberGenerator::setNumbers(int value)
{
	numbers = value;
}

void numberGenerator::setMin(int value)
{
	min = value;
}

void numberGenerator::setMax(int value)
{
	max = value;
}

int numberGenerator::getNumbers()
{
	return numbers;
}

int numberGenerator::getMaximumValue()
{
	return max;
}

int numberGenerator::getMinimumValue()
{
	return min;
}

int numberGenerator::getMainArray()
{
	return *arr;
}

int numberGenerator::getCopyOfArray()
{
	if (arr != NULL) {
		setNullCopy();
		checkIfCopyExsist();
		tab = new int[getNumbers()];
		for (int i = 0; i < getNumbers(); i++) {
			tab[i] = arr[i];
		}
		//std::copy(arr, arr + getNumbers(), tab);
		return *tab;
	}
	else {
		//
	}
}

void numberGenerator::genereteArray()
{
	this->checkIfArrayExsist();
	this->checkIfCopyExsist();
	this->makeMainArray();
}
