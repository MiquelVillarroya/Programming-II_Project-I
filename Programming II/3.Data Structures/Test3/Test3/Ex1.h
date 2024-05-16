#pragma once
/***********************************************************************
MIQUEL VILLARROYA MARTÍ
***********************************************************************/

// Uncomment to perform the tests
#define TEST_EX_1

#if defined(TEST_EX_1)

#include <cassert>
#include <iostream>

using namespace std;

#define INITIAL_SIZE_ARRAY 5
#define INCREASE_SIZE_ARRAY 5
class DynamicQueue
{
public:

	DynamicQueue() :
		_front(-1),
		_back(-1),
		_numElems(0),
		_capacity(INITIAL_SIZE_ARRAY)
	{
		_array = new int[INITIAL_SIZE_ARRAY];
	}

	~DynamicQueue()
	{
		delete[] _array;
	}

	unsigned int size() const
	{
		return _numElems;
	}

	unsigned int capacity() const
	{
		return _capacity;
	}

	void enqueue(const int& elem)
	{
		if (_numElems == _capacity)
		{
			increaseCapacity();
		}

		if (_numElems == 0) {
			_front = 0;
			_back = 0;
		}
		else {
			_back = (_back + 1) % _capacity;
		}

		_array[_back] = elem;
		_numElems++;
	}

	int& front()
	{
		assert(_numElems > 0 && "front() was called, but the queue is empty");
		return _array[_front];
	}

	void dequeue()
	{
		assert(_numElems > 0 && "dequeue() was called, but the queue is empty");
		_front = (_front + 1) % _capacity;
		_numElems--;
	}


	//Function added for testing that prints the queue
	// An "a" after printing means it used the first method
	// where the first pointer goes before the back pointer

	// A "b" after printing means the back pointer is smaller
	// so it iterates the queue by parts

	void Print() 
	{
		if (_front <= _back) {
			for (int i = _front; i < _back + 1; ++i)
			{
				cout << _array[i] << " ";
			}
			cout << "a";
		}
		else
		{
			for (int k = _front; k < _capacity; ++k)
			{
				cout << _array[k] << " ";
			}
			for (int j = 0; j < _back + 1; ++j)
			{
				cout << _array[j] << " ";
			}
			cout << "b";
		}
		cout << endl;
	}

private:

	void increaseCapacity()
	{
		// TODO
		_capacity += INCREASE_SIZE_ARRAY;
		int* arr = new int[_capacity];

		if (_front < _back)
		{
			for (int i = _front; i < _back + 1; ++i)
			{
				arr[i] = _array[_front + i];
			}
		}
		else {
			int i = 0;
			for (int k = _front; k < _capacity - INCREASE_SIZE_ARRAY; ++k, ++i)
			{
				arr[i] = _array[k];
			}
			for (int j = 0; j < _back + 1; ++j, ++i)
			{
				arr[i] = _array[j];
			}
		}
		
		_front = 0;
		_back = _numElems - 1;

		delete _array;
		_array = arr;
	}

	int _front;
	int _back;
	unsigned int _numElems;
	unsigned int _capacity;
	int* _array;
};

#endif

