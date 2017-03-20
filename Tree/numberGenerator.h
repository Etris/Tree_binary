#pragma once
class numberGenerator
{
private:
	int length;
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
public:
	//constr & deconst
	numberGenerator();
	~numberGenerator();
	//settery
	void setLength(int);
	void setMin(int);
	void setMax(int);
	void setNullCopy();
	//gettery
	int getLength();
	int getMaximumValue();
	int getMinimumValue();
	int getMainArray();
	int getCopyOfArray();
	//class methods
	void genereteArray();
};

