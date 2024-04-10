#pragma once
#include <iostream>
using namespace std;

int GetSum(int* array, int size,int start, int end)
{
	//Insert code Here
	
	if (start > size || end > size - 1 || start < 0 || start > end) {
		return -1;
	}
	else {
		int sum = 0;
		for (int i = start; i <= end; ++i) {
			sum += array[i];
		}
		return sum;
	}
}

void SetArray(int* array, int size) {
	//Insert code Here
	for (int i = 0; i < size; ++i) {
		array[i] = size - i;
	}
}

void PrintArray(int* array, int size) {
	//Insert code Here
	for (int i = 0; i < size; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void Ex2() 
{
	//Insert code Here
	int size;
	cout << "Introduce the array size: ";
	cin >> size;
	int* array = new int[size];
	SetArray(array, size);
	PrintArray(array, size);
	cout << GetSum(array, size, 1, 4) << endl;
	cout << GetSum(array, size, 9, 9) << endl;
	cout << GetSum(array, size, 19, 9) << endl;
}
