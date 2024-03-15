#pragma once
#include <iostream>
using namespace std;

void printArray(int* array, int size) {
	for (int i = 0; i < size; ++i) {
		cout << *(array + i) << " ";
	}
	cout << endl;
}

int GetSum(int* array, int size, int start, int end)
{
	//Insert code Here
	if (end >= size || start < 0 || start > end) {
		return -1;
	}
	int sum = 0;
	for (int i = start; i <= end; ++i) {
		sum += *(array + i);
	}

	return sum; 
}

void SetArray(int* array, int size) {
	//Insert code Here

	for (int i = 0; i < size; ++i) {
		*(array + i) = size - i;
	}
}

void Ex2() 
{
	//Insert code Here
	int* array = new int[10];
	SetArray(array, 10);
	printArray(array, 10);
	cout << GetSum(array, 10, 1, 4) << endl;
	delete[] array;
}
