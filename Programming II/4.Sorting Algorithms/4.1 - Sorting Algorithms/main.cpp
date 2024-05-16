#include <iostream>
using namespace std;

void PrintArray(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void Swap(int* val1, int* val2)
{
	int aux = *val1;
	*val1 = *val2;
	*val2 = aux;
}

void BubbleSort(int* array, int size)
{
	int counter = 0;
	bool anySwap = 0;

	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
				anySwap = true;
				counter++;
			}
		}
		PrintArray(array, size);
		if (!anySwap) break;

	}

	cout << "Number of changes: " << counter << endl;
}

int main()
{
	printf("Bubble Sort: \n");
	
	int array1[] = { 8, 7, 5, 6, 3, 1, 1, 0 };
	int size = 8;
	BubbleSort(array1, size);
	PrintArray(array1, size);
}