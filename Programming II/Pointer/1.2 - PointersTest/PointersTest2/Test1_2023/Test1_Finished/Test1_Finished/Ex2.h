#pragma once
#include <iostream>
using namespace std;

int GetSum(int* array, int size,int start, int end)
{
	if (start < 0 || end >= size || start > end)
		return -1;
	int sum = 0;
	for (size_t i = start; i <= end; i++)
	{
		sum += *(array + i);
	}

	return sum;
}

void SetArray(int* array, int size) {
	for (size_t i = 0; i < size; i++)
	{
		*(array + i) = size - i;
	}
}

void Ex2() 
{
	int* a = new int[10]();
	SetArray(a, 10);
	cout << GetSum(a, 10, 1, 10);
	delete[]a;
}
