#include <iostream>
using namespace std;

void Ex1();
void Ex2();
void Ex3();
void Ex4();

void countUp(unsigned int val);
int numTrues(bool vec[], int sizeVec, unsigned int index);
bool searchRec(int vec[], int sizeVec, unsigned int index, int val);
int sumElemsRec(int vec[], unsigned int sizeVec, unsigned int index);


int main() {
	//EX1
	cout << "Ex 1: " << endl;
	Ex1();

	//EX2
	cout << endl <<"Ex 2: " << endl;
	Ex2();

	//EX3
	cout << endl << "Ex 3: " << endl;
	Ex3();

	//EX4
	cout << endl << "Ex 4: " << endl;
	Ex4();

}

void countUp(unsigned int val)
{
	if (val == -1) return;
	countUp(val - 1);
	cout << val << endl;

}

int numTrues(bool vec[], int sizeVec, unsigned int index)
{
	//Iterating the vec end to front
		
	if (vec[sizeVec - 1] == 1)	index++;
	if (sizeVec == 1) return index;
	numTrues(vec, sizeVec - 1, index);
}

bool searchRec(int vec[], int sizeVec, unsigned int index, int val)
{
	//Iterating the vec from end to front
	/*
		if (vec[sizeVec] == val) return true;
		else if (sizeVec == 0) return false;
		else searchRec(vec, sizeVec - 1, index, val);
	*/

	//Iterating the vec from front to end
	if (vec[index] == val) return true;
	else if ((index + 1) >= sizeVec) return false;
	else searchRec(vec, sizeVec, index + 1, val);
}

int sumElemsRec(int vec[], unsigned int sizeVec, unsigned int index)
{
	//Iterating from end to front

	index += vec[sizeVec - 1];
	if (sizeVec == 1) return index;
	sumElemsRec(vec, sizeVec - 1, index);
}

void Ex1()
{
	countUp(4);
	cout << endl;
}

void Ex2()
{
	bool vec[] = {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0 }; // (-) trues
	int sizeVec = 12;
	unsigned int index = 0; //Starting point (or counter?), better counter

	int counter;
	counter = numTrues(vec, sizeVec, index);

	cout << "Number of 'trues: " << counter << endl;
}

void Ex3()
{
	bool flag;

	int vec[] = { 1, 2, 3, 4, 5, 6, 7, 9 }; //Six trues
	int sizeVec = 8;
	unsigned int index = 0; //Starting point (or counter?)
	int val = 10;

	flag = searchRec(vec, sizeVec, index, val);

	cout << "Is number in array: " << flag << endl;
}

void Ex4()
{
	int vec[] = { 1, 2, 3, 4, 5, 6, 7, 8, 1 }; //Sum = 37
	int sizeVec = 9;
	unsigned int index = 0; //Starting point (or counter?)

	int sum;
	sum = sumElemsRec(vec, sizeVec, index);

	cout << "Sum: " << sum << endl;
}