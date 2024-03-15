#include <iostream>
using namespace std;


void ex0() {

	int num = 3;
	cout << &num << endl;
	int* ptr = &num;
	cout << ptr << endl;
	cout << *ptr << endl;

	*ptr = 4;

	cout << num << endl;
}

void ex1() {
	int a = 3;
	int* ptr = &a;
	int** ptr2 = &ptr;

	cout << *ptr << endl;
	cout << **ptr2 << endl;
	cout << a << endl;
 
}

void ex2() {
	int vec[3] = { 1,2,3 };
	int* p = vec;

	cout << p << endl;
	cout << *p << endl;
}

void ex3() {
	int vec[3] = { 1,2,3 };
	int* ptr = vec;

	for (int i = 0; i < 3; i++) {
		cout << ptr[i] << " ";
	}
	cout << endl;

	for (int j = 0; j < 3; j++) {
		cout << *(ptr+j) << " ";
	}
	cout << endl;

	for (int k = 0; k < 3; k++) {
		cout << *ptr++ << " ";
	}
}

void add5(int* num) {
	*num += 5;
}


void ex4() {
	int num = 5;
	add5(&num);
	cout << num << endl;
}

int sumArray(int* a, int size) {

	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += *(a + i);
	}
	return sum;
}

void ex5() {
	int array[3] = { 1,2,3 };

	cout << sumArray(array, 3);
}

int main() {

	//cout << "Ex 0:" << endl;
	//ex0();
	//cout << endl;

	//cout << "Ex 1:" << endl;
	//ex1();
	//cout << endl;

	//cout << "Ex 2:" << endl;
	//ex2();
	//cout << endl;

	//cout << "Ex 3:" << endl;
	//ex3();
	//cout << endl;

	cout << "Ex 4:" << endl;
	ex4();
	cout << endl;

	cout << "Ex 5:" << endl;
	ex5();
	cout << endl;

	return 0;
}