#include "exs.h";
#include <iostream>

using namespace std;

void sum(int val1, int val2, int* result) {
	*result = val1 + val2;
}

void ex2() {
	
	cout << "First value:" << endl;
	int val1, val2, result;
	cin >> val1;
	cout << "Second value:" << endl;
	cin >> val2;

	sum(val1, val2, &result);

	cout << result << endl;
}