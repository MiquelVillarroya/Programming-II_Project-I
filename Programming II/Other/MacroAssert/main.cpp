
//#define NDEBUG
#include "assert.h"
#include <iostream>

float divide(float a, float b)
{
	assert(b != 0);

	return a / b;
}

int main()
{
	float d = divide(3, 0);
	std::cout << d;
}