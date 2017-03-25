#pragma once
class numberGenerator
{
private:
	int numbers;
	int min, max;
	int randNumber();
	int * arr, *tab;
	void makeMainArray();
	void checkIfArrayExsist();
	void checkIfCopyExsist();
	void setNullArray();
	void nullArray();
	void getUnique(int);
	bool isInArray(int, int);
	void sort();
public:
	//constr & deconst
	numberGenerator();
	~numberGenerator();
	//settery
	void setNumbers(int);
	void setMin(int);
	void setMax(int);
	void setNullCopy();
	//gettery
	int getNumbers();
	int getMaximumValue();
	int getMinimumValue();
	int * getMainArray();
	int * getCopyOfArray();
	//class methods
	void genereteArray();
	void genereteSortedArray();
};

