#pragma once
#include <iostream>
using namespace std;


// Uncomment to perform the tests
#define TEST_EX_2
class Rectangle {

public:
	Rectangle() {}
	Rectangle(int width, int height, int id) {
		this->height = height;
		this->width = width;
		this->id = id;
	}

	int area() const {
		return height * width;
	}
	int getId() const {
		return id;
	}

private:
	int width, height,id;
};

void swap(Rectangle* rect1, Rectangle* rect2)
{
	Rectangle* aux = rect1;
	rect1 = rect2;
	rect2 = aux;
}

void PrintRect(Rectangle* rect, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "ID: " << rect[i].getId() << " Area: " << rect[i].area() << endl;
	}
	cout << endl;
}

void bubbleSort(Rectangle* rect, int size) {
	
	for (int i = 0; i < size - 1; ++i)
	{
		PrintRect(rect, size);

		for (int j = 0; j < size - i - 1; ++j)
		{
			if (rect[j].area() > rect[j + 1].area())
			{
				swap(rect[j], rect[j + 1]);

			}
		}
	}

}

