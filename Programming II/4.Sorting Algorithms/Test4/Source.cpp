#include "Ex1.h"
#include "Ex2.h"


#include "SimpleUnitTest.h"
#include <stdlib.h> 
#include <time.h> 

#include <iostream>

using namespace std;

void TestEx1();
void TestEx2();


int main() {

	TestEx1();
	TestEx2();

	return 0;


}

void TestEx1() {
#if defined(TEST_EX_1)
	int* a = new int[6]{ 2,1,3,4,5,6 };
	int* b = new int[6]{ 3,2,6,1,4,5 };
	int* c = new int[6]{ 6,5,3,4,2,1 };

	sort(a, 6);
	sort(b, 6);
	sort(c, 6);

	bool res1 = a[0] == 6;
	bool res2 = a[1] == 5;
	bool res3 = a[2] == 4;
	bool res4 = a[3] == 3;
	bool res5 = a[4] == 2;
	bool res6 = a[5] == 1;

	bool res1_b = b[0] == 6;
	bool res2_b = b[1] == 5;
	bool res3_b = b[2] == 4;
	bool res4_b = b[3] == 3;
	bool res5_b = b[4] == 2;
	bool res6_b = b[5] == 1;

	bool res1_c = b[0] == 6;
	bool res2_c = b[1] == 5;
	bool res3_c = b[2] == 4;
	bool res4_c = b[3] == 3;
	bool res5_c = b[4] == 2;
	bool res6_c = b[5] == 1;

	TEST(": Exercise 1: sorting ", res1 && res2 && res3 && res4 && res5 && res6 &&
		res1_b && res2_b && res3_b && res4_b && res5_b && res6_b &&
		res1_c && res2_c && res3_c && res4_c && res5_c && res6_c);

#else
	cout << "Uncomment #define TEST_EX_1 in Ex1.h to perform test 1" << endl << endl;
#endif

}

void TestEx2() {
#if defined(TEST_EX_2)
	Rectangle* array = new Rectangle[6];
	array[0] = Rectangle(2, 3, 0);
	array[1] = Rectangle(1, 1, 1);
	array[2] = Rectangle(3, 3, 2);
	array[3] = Rectangle(3, 3, 3);
	array[4] = Rectangle(2, 2, 4);
	array[5] = Rectangle(4, 4, 5);



	bubbleSort(array, 6);
	cout << endl;


	bool res1 = array[0].area() == 1 && array[0].getId() == 1;
	bool res2 = array[1].area() == 4 && array[1].getId() == 4;
	bool res3 = array[2].area() == 6 && array[2].getId() == 0;
	bool res4 = array[3].area() == 9 && array[3].getId() == 2;
	bool res5 = array[4].area() == 9 && array[4].getId() == 3;
	bool res6 = array[5].area() == 16 && array[5].getId() == 5;

	TEST(": Exercise 2: Rectangle sorting ", res1 && res2 && res3 && res4 && res5 && res6);
#else
	cout << "Uncomment #define TEST_EX_2 in Ex2.h to perform test 2" << endl << endl;
#endif
}