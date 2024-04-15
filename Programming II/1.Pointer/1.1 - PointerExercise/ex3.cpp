#include "exs.h";
#include <iostream>

using namespace std;


void reverse(int* array, int sizeArray) {
	for (int i = sizeArray - 1; i >= 0; i--) {
		cout << *(array+i) << endl;
	}
}

void ex3() {
	int array[10];
	for (int i = 0; i < 10; i++) {
		cout << "Introduce digit number" << i + 1 << ":";
		cin >> array[i];
	}
	reverse(array, 10);
}