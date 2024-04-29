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
			cout << array[i] << " ";
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
		if (empty())	_front++;
		else if (_back % _capacity == 0)
		{
			if (size() < _capacity)
			{
				_back = 0;
			}
			else {
				//IncreaseMemory();
			}
		}
		else {
			_back++;
			_array[_back] = value;
		}
	}
	int dequeue()
	{
		if(!empty())
		{
			if (_front % _capacity == 0)
			{
				_front = 0;
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
		if (_front == -1)	return 0;
		else if (_front >= _back) return _back - _front + 1;
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
			for (int i = _front; i < _back; ++i)
			{
				cout << _array[i] << " ";
			}
		}
		else if (_front > _back)
		{
			for (int i = _front; i < size(); ++i)
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
	}

private:
	int _front; //Index to the front (-1 if empty)
	int _back; //Index to the back (-1 if empty)
	int* _array; //Dynamically allocated array
	int _capacity; //Maximum capacity
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
		q.PrintQueue();

		q.enqueue(1);
		q.PrintQueue();

		q.enqueue(2);
		q.PrintQueue();

		q.enqueue(3);
		q.PrintQueue();

	}
}
