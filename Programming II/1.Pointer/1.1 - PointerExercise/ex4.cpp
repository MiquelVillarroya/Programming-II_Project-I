#include "exs.h";
#include <iostream>

using namespace std;

void printArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << " " << array[i];
	}
	cout << endl;
}

int abs(int num) {
	num -= num * 2;
	return num;
}

void absSwap(int* arr1, int sizeArr1, int* arr2, int sizeArr2) {
	int num = 0;
	for (int i = 0; i < sizeArr1; i++) {
		num = arr2[i];
		if (arr2[i] < 0) {
			num = abs(arr2[i]);
		}
		arr1[i] = num;
	}
}

void ex4() {
	int* arr1 = (int*) calloc(20, sizeof(int));
	int* arr2 = (int*) malloc(20*sizeof(int));
	for (int i = 0; i < 20; i++) {
		cin >> arr2[i];
	}

	absSwap(arr1,20,arr2,20);

	printArray(arr1, 20);
	printArray(arr2, 20);
	
	free(arr1);
	free(arr2);
}