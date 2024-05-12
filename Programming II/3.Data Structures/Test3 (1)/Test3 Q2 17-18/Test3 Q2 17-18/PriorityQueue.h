#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <cassert>

template<class T>
class PriorityQueue
{
public:

	PriorityQueue() :
		_front(nullptr),
		_numElems(0)
	{ }

	~PriorityQueue()
	{
		clear();
	}

	unsigned int size() const
	{
		return _numElems;
	}

	bool empty() const
	{
		return _numElems == 0;
	}

	T &front()
	{
		assert(_numElems > 0 && "Cannot obtain the front of an empty queue");
		return _front->value;
	}

	const T &front() const
	{
		assert(_numElems > 0 && "Cannot obtain the front of an empty queue");
		return _front->value;
	}

	void enqueue(const T &value, int priority)
	{
		// TODO
		Node* node = new Node;
		node->value = value;
		node->priority = priority;

		if (empty())
		{
			_front = node;
			node->next = nullptr;
		}
		else if (_front->priority < node->priority)
		{
			node->next = _front;
			_front = node;
		}
		else
		{
			Node* tempNode = new Node;
			tempNode = _front;
			while (true)
			{
				if (tempNode->next == nullptr)
				{
					tempNode->next = node;
					node->next = nullptr;
					break;
				}
				else if (tempNode->next->priority > node->priority)
				{
					tempNode = tempNode->next;
				}
				else if (tempNode->next->priority <= node->priority)
				{
					node->next = tempNode->next;
					tempNode->next = node;
					break;
				}
			}
		}

		_numElems++;
	}

	void dequeue()
	{
		assert(_numElems > 0 && "Cannot dequeue from an empty queue");

		Node *newFront = _front->next;
		delete _front;
		_front = newFront;
		_numElems--;
	}

	void clear()
	{
		while (!empty())
		{
			dequeue();
		}
	}

private:

	struct Node
	{
		T value;
		int priority;
		Node *next;
	};

	Node *_front;
	unsigned int _numElems;
};

#endif // PRIORITY_QUEUE_H
