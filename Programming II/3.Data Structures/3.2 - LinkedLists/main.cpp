#include <iostream>
using namespace std;

class List {
private:

	// Internal struct for list nodes
	struct Node {
		int value;
		Node* next;
		Node* prev;
	};

	// List internals
	Node* first = nullptr;
	Node* last = nullptr;
	unsigned int num_elems = 0;

public:

	//Constructor and destructor
	List() //Is constructor OK?
	{
		first = nullptr;
		last = nullptr;
		num_elems = 0;
	}
	~List()
	{
		clear();
	}

	//Modifiers
	void push_front(const int& value)
	{
		insert(0, value);

		//if (num_elems == 0)
		//{
		//	first = last = new Node;
		//	first->value = value;
		//	first->prev = nullptr;
		//	first->next = nullptr;
		//}
		//else
		//{
		//	Node* node = new Node;
		//	node->value = value;
		//	node->prev = nullptr;
		//	node->next = first;
		//	first->prev = node;
		//	first = node;
		//}
		//num_elems++;
	}
	void push_back(const int& value)
	{
		insert(num_elems - 1, value);
		//if (num_elems == 0)
		//{
		//	last = first = new Node;
		//	last->value = value;
		//	last->next = nullptr;
		//	last->prev = nullptr;
		//}
		//else
		//{
		//	Node* node = new Node;
		//	node->value = value;
		//	node->prev = last;
		//	node->next = nullptr;
		//	last->next = node;
		//	last = node;
		//}
		//num_elems++;
	}
	void pop_front()
	{
		erase(0);
		
		//first = first->next;
		//delete[] first->prev;
		//num_elems--;
	}
	void pop_back()
	{
		erase(num_elems - 1);

		//last = last->prev;
		//delete[] last->next;
		//num_elems--;
	}
	void insert(unsigned int position, const int& value)
	{
		if (num_elems == 0)
		{
			first = last = new Node;
			first->value = value;
			first->prev = nullptr;
			first->next = nullptr;
		}
		else {
			Node* current = first;
			for (int i = 1; i < position; ++i)
			{
				current = current->next;			//Node in the position before the one to be inserted to
			}
			Node* node = new Node;
			node->value = value;

			if (position == num_elems)
			{
				node->next = nullptr;
				node->prev = current;
				current->next = node;
			}
			else if (position == 0)
			{
				node->next = current;
				node->prev = nullptr;
				current->prev = node;
				first = node;
			}
			else
			{
				node->next = current->next;
				node->prev = current;
				current->next->prev = node;
				current->next = node;
			}
		}
		num_elems++;
	}
	void erase(unsigned int position)
	{
		if (num_elems > 0)
		{
			Node* current = first;
			for (int i = 1; i < position; ++i)
			{
				current = current->next;			//Node in the position before the one to be inserted to
			}

			if (position == 0)
			{
				first = current->next;
				delete[] first->prev;
				first->prev = nullptr;
			}
			else if (position + 1 == num_elems)
			{
				last = current;
				delete[] last->next;
				last->next = nullptr;

			}
			else
			{
				current->next = current->next->next;
				delete current->next->prev;
				current->next->prev = current;
			}
			num_elems--;
		}
	}
	void clear()
	{
		for (int i = 0; i < num_elems; ++i)
		{
			Node* aux = first;
			for (int j = num_elems - 1; j > i; --j)
			{
				aux = aux->next;
			}
			delete aux;
		}
		num_elems = 0;
	}

	void PrintList()
	{
		if (num_elems > 0)
			for (int i = 0; i < num_elems; ++i)
			{
				Node* aux = first;
				for (int j = 0; j < i; ++j)
				{
					aux = aux->next;
				}
				cout << aux->value << " ";
			}
		cout << endl;
	}

	//Getters
	int &front()
	{
		return first->value;
	}
	int &back()
	{
		return last->value;
	}
	int &value_at(unsigned int position)
	{
		Node* aux = first;
		for (int i = 0; i < position; ++i)
		{
			aux = aux->next;
		}
		return aux->value;
	}
	bool empty() const
	{
		if (num_elems == 0) return true;
		return false;
	}
	unsigned int size() const
	{
		return num_elems;
	}

};


int main() {

	List l;
	l.push_back(4);
	l.push_front(3);
	l.PrintList();

	l.push_front(2);
	l.PrintList();

	l.push_front(1);
	l.PrintList();

	l.push_back(5);
	l.PrintList();

	cout << "Front: " << l.front() << " Back: " << l.back() << " 2nd value: " << l.value_at(1) <<
	" 4th value: " << l.value_at(3) << " Size: " << l.size() << endl;

	l.pop_front();
	l.PrintList();

	l.pop_back();
	l.PrintList();

	l.insert(0, 0);
	l.PrintList();

	l.insert(2, 7);
	l.PrintList();

	l.insert(5, 99);
	l.PrintList();
	//0 2 7 3 5 99

	l.erase(4);
	l.PrintList();

	l.erase(4);
	l.PrintList();

	l.erase(0);
	l.PrintList();

	cout << "Empty? " << l.empty() << " Size: " << l.size() << endl;
	
	l.clear();
	cout << "Empty? " << l.empty();
}