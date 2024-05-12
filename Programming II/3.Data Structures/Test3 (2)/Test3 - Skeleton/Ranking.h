#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <assert.h>
#include <iostream>

using namespace std;

// Uncomment to perform the tests
#define TEST_3_RANKING

class Ranking
{
public:

	Ranking() :
		first(nullptr),
		num_elems(0)
	{ }

	~Ranking()
	{
		clear();
	}

	int size() const
	{
		return num_elems;
	}

	bool empty() const
	{
		return num_elems == 0;
	}

	const char *head()
	{
		assert(num_elems > 0 && "The ranking is empty");
		return first->name;
	}

	const char *head() const
	{
		assert(num_elems > 0 && "The ranking is empty");
		return first->name;
	}

	void push_front(const char *name)
	{
		Node *new_node = new Node;
		new_node->name = name;
		new_node->prev = nullptr;
		new_node->next = first;
		if (first != nullptr) {
			first->prev = new_node;
		}
		first = new_node;
		num_elems++;
	}

	void clear()
	{
		Node *it = first;
		while (it != nullptr) {
			Node *to_delete = it;
			it = it->next;
			delete to_delete;
		}
	}

	int find_player_position(const char *name)
	{
		// TODO: Insert your code here

		Node* tempNode = new Node;
		tempNode = first;

		for (int i = 0; i < num_elems; ++i)
		{
			if (tempNode->name == name)
			{
				return i;
			}

			tempNode = tempNode->next;
		}

		return -1;
	}

	void advance(int position)
	{
		// TODO: Insert your code here
		if (position != 0) {
			Node* aux1 = new Node;
			aux1 = first;

			for (int i = 0; i < position; ++i)
			{
				aux1 = aux1->next;
			}

			Node* aux2 = new Node;
			aux2 = first;

			for (int i = 0; i < position - 2; ++i)
			{
				aux2 = aux2->next;
			}
			if (position == 1)
			{
				aux2->next = aux1->next;
				aux1->next = aux2;
				first = aux1;
			}
			else
			{
				aux2->next->next = aux1->next;
				aux1->next = aux2->next;
				aux2->next = aux1;
			}

		}
		PrintRace();
	}

	void PrintRace()
	{
		Node* it = new Node;
		it = first;

		for (int i = 0; i < num_elems; ++i)
		{
			cout << it->name << " ";
			it = it->next;
		}
		cout << endl;
	}

private:

	struct Node
	{
		const char *name = nullptr;
		Node *next = nullptr;
		Node *prev = nullptr;
	};

	Node *first;
	int num_elems;
};

#endif // PRIORITY_QUEUE_H
