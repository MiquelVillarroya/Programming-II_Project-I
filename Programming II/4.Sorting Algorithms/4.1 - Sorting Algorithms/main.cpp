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

void SelectionSort(int* array, int size)
{
	int* array2 = new int[size];
	int maxValue, value, idx;

	//Find max value
	maxValue = 0;
	for (int i = 0; i < size; ++i)
		if (array[i] > maxValue)  maxValue = array[i];

	//Copy into new array the ordered values
	for (int i = 0; i < size; ++i)
	{
		value = maxValue;
		idx = 0;
		for (int j = 0; j < size; ++j)
		{
			if (array[j] < value)
			{
				value = array[j];
				idx = j;
			}
		}
		array[idx] = maxValue;
		array2[i] = value;
	}

	//Copy the new array into the old one
	for (int i = 0; i < size; ++i)
	{
		array[i] = array2[i];
	}

	//Delete the new array
	delete[] array2;
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

void Merge(int* array, int const start, int const mid, int const end)
{
	int i, j, k; //i and j are the indexes of the two arrays two merge, k is the index of the array we are merging to
	int sizeR, sizeL;

	sizeL = mid - start + 1;
	sizeR = end - mid;

	int* L = new int[sizeL];
	int* R = new int[sizeR];

	for (int i = 0; i < sizeL; ++i)
	{
		L[i] = array[start + i];
	}
	for (int j = 0; j < sizeR; ++j)
	{
		R[j] = array[mid + 1 + j];
	}

	i = 0;
	j = 0;
	k = start;

	while (i < sizeL && j < sizeR)
	{
		if (L[i] < R[i])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < sizeL)
	{
		array[k] = L[i];
		i++;
		k++;
	}
	while (j < sizeR)
	{
		array[k] = R[j];
		j++;
		k++;
	}
	
}

void MergeSort(int* array, int const start, int const end)
{
	//Base
	if (start < end)
	{
		//Divide the array
		int mid = start + (end - start) / 2;

		MergeSort(array, start, mid);
		MergeSort(array, mid + 1, end);

		//Merge the array, as we do so we keep the smaller values on the left to order the array
		Merge(array, start, mid, end);
	}
}


int Partition(int* array, int start, int end)
{
	int pivot = array[end];
	int idx = 0;
	for (int i = 0; i < end; ++i)
	{
		if (array[i] <= array[end])
		{
			swap(array[i], array[idx]);
			idx++;
		}
	}
	swap(array[idx], array[end]);

	return idx;
}

void QuickSort(int* array, int start, int end)
{
	if (start < end)
	{
		int idx;
		idx = Partition(array, start, end);

		QuickSort(array, start, idx - 1);
		QuickSort(array, idx + 1, end);
	}
}

struct BstNode
{
	int data;
	BstNode* leftChild;
	BstNode* rightChild;
};

BstNode* GetNewNode(int value)
{
	BstNode* node = new BstNode;
	node->data = value;
	node->rightChild = nullptr;
	node->leftChild = nullptr;
	return node;
}

BstNode* Insert(BstNode* root, int value)
{
	if (root == NULL)
	{
		root = GetNewNode(value);
		return root;
	}
	else if (value <= root->data)
	{
		root->leftChild = Insert(root->leftChild, value);
		return root;
	}
	else if (value > root->data)
	{
		root->rightChild = Insert(root->rightChild, value);
		return root;
	}
}

void StoreSorted(BstNode* root, int* array, int& i)
{
	if (root != nullptr)
	{
		StoreSorted(root->leftChild, array, i);
		array[i++] = root->data;
		StoreSorted(root->rightChild, array, i);
	}
}

void TreeSort(int* array, int size)
{
	BstNode* root = nullptr;

	for (int i = 0; i < size; ++i)
	{
		root = Insert(root, array[i]);
	}

	int i = 0;
	StoreSorted(root, array, i);
}


int main()
{
	printf("Bubble Sort: \n");
	
	int array[] = { 8, 7, 5, 6, 3, 1, 1, 0 };
	int size = sizeof(array) / sizeof(array[0]);
	PrintArray(array, size);

	//SelectionSort(array1, size);
	//BubbleSort(array1, size);
	//MergeSort(array, 0, size - 1);
	//QuickSort(array, 0, size - 1);
	//TreeSort(array, size);


	PrintArray(array, size);
}