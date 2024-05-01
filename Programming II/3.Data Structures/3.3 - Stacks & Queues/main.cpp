#define NDEBUG
#include "assert.h"
#include <iostream>
using namespace std;

#define INITIAL_MEMORY_SIZE		5
#define MEMORY_INCREASE_SIZE	5

class Stack
{
public:
	//Ctor. and Dtor.
	Stack()
	{
		_top = -1;
		array = new int[5];
	}
	~Stack() {
		delete[] array;
	}

	//Modifier
	void push (int value)
	{
		if (true)
		{
			_top++;
			array[_top] = value;
		}
	}
	void pop()
	{
		if (!empty()) _top--;
	}

	//Getters
	int top() const
	{
		assert(_top != -1);
		return array[_top];
	}
	bool empty() const
	{
		return (_top == -1);
	}

	//PrintStack
	void printStack()
	{
		for (int i = 0; i < _top + 1; ++i)
		{
			//cout << array[i] << " ";
		}
		cout << endl;
	}

private:
	int _top;
	int* array;

};

class Queue
{
public:
	//Ctor. and Dtor.
	Queue()
	{
		_front = -1;
		_back = -1;
		_array = new int[INITIAL_MEMORY_SIZE];
		_capacity = INITIAL_MEMORY_SIZE;
	}
	~Queue()
	{
		delete[] _array;
	}

	//Modifiers
	void enqueue(int value)
	{
		if (size() >= _capacity)
		{
			IncreaseMemory();
		}
		if ((_back + 1) % _capacity == 0 && _back != -1)
		{
				_back = 0;
		}
		else {
			if (empty())	_front++;
			_back++;
		}
		_array[_back] = value;
	}
	int dequeue()
	{
		if(!empty())
		{
			if ((_front + 1) % _capacity == 0 && _front != 1)
			{
				_front = 0;
			}
			else if (size() == 1)
			{
				_front = -1;
				_back = -1;
			}
			else
			{
				_front++;
				return _front - 1;
			}
		}
	}

	//Getters
	int size() const
	{
		if (_front == -1) return 0;
		else if (_back >= _front) return _back - _front + 1;
		else return _capacity - (_front - _back) + 1;

	}
	bool empty() const
	{
		if (size() == 0) return true;
		return false;
	}

	//Print Queue
	void PrintQueue()
	{
		if (_front <= _back)
		{
			for (int i = _front; i <= _back; ++i)
			{
				cout << _array[i] << " ";
			}
		}
		else if (_front > _back)
		{
			for (int i = _front; i < _capacity; ++i)
			{
				cout << _array[i] << " ";
			}
			for (int i = 0; i <= _back; ++i)
			{
				cout << _array[i] << " ";
			}
		}
		cout << endl;
		cout << "Capacity: " << _capacity << endl;
		cout << "Size: " << size() << endl;
		cout << "Empty? " << empty() << endl << endl;
	}

private:
	int _front; //Index to the front (-1 if empty)
	int _back; //Index to the back (-1 if empty)
	int* _array; //Dynamically allocated array
	int _capacity; //Maximum capacity

	void IncreaseMemory()
	{
		_capacity += MEMORY_INCREASE_SIZE;
		int* arr = new int[_capacity];
		if (_front <= _back)
		{
			for (int i = _front; i <= _back; ++i)
			{
				arr[i] = _array[i];
			}
		}
		else if (_front > _back)
		{
			for (int i = 0; i <= _back; ++i)
			{
				arr[i] = _array[i];
			}
			for (int i = _front; i < _capacity; ++i)
			{
				arr[i + MEMORY_INCREASE_SIZE] = _array[i];
			}
			_front += MEMORY_INCREASE_SIZE;

		}
		//printArray(arr, _capacity);
		delete[] _array;
		_array = arr;
	}

	void printArray(int *arr, int size)
	{
		for (int i = 0; i < size; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	
	{
		Stack s;

		s.printStack();

		s.push(6);
		s.printStack();

		s.push(7);
		s.printStack();

		s.push(8);
		s.printStack();

		s.pop();
		s.printStack();

		cout << "Top value: " << s.top();
		cout << " Is Empty? " << s.empty() << endl;
		s.printStack();

		s.pop();
		s.printStack();

		s.pop();
		s.printStack();

		cout << "Top value: " << s.top();
		cout << " Is Empty? " << s.empty() << endl;
		s.printStack();
	}
	{
		Queue q;
		q.PrintQueue(); //Empty

		q.enqueue(1);
		q.PrintQueue();

		q.enqueue(2);
		q.PrintQueue();

		q.enqueue(3);
		q.PrintQueue();

		q.dequeue();
		q.PrintQueue();
		
		q.dequeue();
		q.PrintQueue();
		
		q.dequeue();
		q.PrintQueue(); //Empty

		q.enqueue(1);
		q.enqueue(2);
		q.enqueue(3);
		q.enqueue(4);
		q.enqueue(5);
		q.dequeue();
		q.dequeue();
		q.PrintQueue();

		q.enqueue(6);
		q.PrintQueue();

		q.enqueue(7);
		q.PrintQueue();

		q.dequeue();
		q.PrintQueue();

		q.enqueue(8); //4, 5, 6, 7, 8
		q.PrintQueue();
	
		q.enqueue(9);
		q.PrintQueue();

		q.dequeue();
		q.PrintQueue();

		q.dequeue();
		q.PrintQueue();

		q.dequeue();
		q.PrintQueue();

		q.dequeue();
		q.PrintQueue();

		q.dequeue();
		q.PrintQueue();

		q.dequeue();
		q.PrintQueue();
	}
}
