#include "exs.h";
#include <iostream>

using namespace std;

void printCharPtr(char* myString) {
	for (int i = 0; *(myString + i) != '\0'; ++i) {
		cout << *(myString + i);
	}
	cout << endl;
}

int sizeWord(char* myString){
	int i = 0;
	while (*(myString + i)) {
		i++;
	}
	return i;
}

void concat(char* word1, char* word2, char* result) {
	int i = 0;
	for (i = 0; word1[i] != '\0'; ++i) {
		result[i] = word1[i];
	}
	for (int j = 0; word2[j] != '\0'; ++i, ++j) {
		result[i] = word2[j];
	}
	result[i] = '\0';
}

void ex5() {

	char* word1 = new char[60];
	char* word2 = new char[60];

	cout << "First word: ";
	cin >> word1;
	cout << endl << "Second word: ";
	cin >> word2;
	int sizeSum = sizeWord(&word1[0]) + sizeWord(&word2[0]) + 1;

	//cout << sizeSum;
	char* result = new char[sizeSum];
	
	concat(&word1[0], &word2[0], result);

	printCharPtr(result);

	delete[] word1, word2, result;
}