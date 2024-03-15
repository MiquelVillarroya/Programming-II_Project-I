#include "exs.h";
#include <iostream>

using namespace std;

void printArrayPtr(int* array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << endl;
	}
}

void ex1() {
	
	int array1[10] = {0,1,2,3,4,5,6,7,8,9};
	int* array2[10];

	for (int i = 0; i < 10; i++) {
		array2[i] = &array1[i];
	}
	printArrayPtr(array2, 10);
}