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
		if (num_elems == 0)
		{
			first = last = new Node;
			first->value = value;
			first->prev = nullptr;
			first->next = nullptr;
		}
		else
		{
			Node* node = new Node;
			node->value = value;
			node->prev = nullptr;
			node->next = first;
			first->prev = node;
			first = node;
		}
		num_elems++;
	}
	void push_back(const int& value)
	{
		if (num_elems == 0)
		{
			last = first = new Node;
			last->value = value;
			last->next = nullptr;
			last->prev = nullptr;
		}
		else
		{
			Node* node = new Node;
			node->value = value;
			node->prev = last;
			node->next = nullptr;
			last->next = node;
			last = node;
		}
		num_elems++;
	}
	void pop_front()
	{
		first = first->next;
		delete[] first->prev;
		num_elems--;
	}
	void pop_back()
	{
		last = last->prev;
		delete[] last->next;
		num_elems--;
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
		/*else
		{
			Node* node = new Node;
			node = first;
			Node* aux = new Node;
			for (int i = 0; i < position - 1; ++i)
			{
				node = node->next;
			}
			aux->value = value;
			aux->next = node->next;
			aux->next->prev = aux;
			node->next = aux;
			aux->prev = node;
		}*/
		num_elems++;
	}
	void erase(unsigned int position)
	{

	}
	void clear()
	{

	}

	void PrintList()
	{
		for (int i = 0; i < num_elems; ++i)
		{
			Node* aux = first;
			for(int j = 0; j < i; ++j)
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
	
	l.insert(2, 7);
	l.PrintList();


	l.PrintList();

	cout << "Empty? " << l.empty() << " Size: " << l.size() << endl;
	cout << "Empty? " << l.empty();
}