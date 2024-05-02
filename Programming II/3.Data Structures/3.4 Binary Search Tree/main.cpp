#include <iostream>
using namespace std;

struct BstNode
{
	int data;
	BstNode* leftChild;
	BstNode* rightChild;
};

BstNode* GetNewNode(int value)
{
	BstNode* newNode = new BstNode();
	newNode->data = value;
	newNode->leftChild = nullptr;
	newNode->rightChild = NULL;
	return newNode;

}

void Insert(BstNode** root, int value)
{
	if (*root == NULL)
	{
		*root = GetNewNode(value);
	}
	else if (value <= (*root)->data)
	{
		Insert(&(*root)->leftChild, value);
	}
	else if (value > (*root)->data)
	{
		Insert(&(*root)->rightChild, value);
	}
}

bool Search(BstNode** root, int value)
{
	if ((*root)->data == value)
	{
		return true;
	}
	else if ((*root)->leftChild == nullptr && (*root)->rightChild == nullptr)
	{
		return false;
	}
	else if (value <= (*root)->data)
	{
		Search(&(*root)->leftChild, value);
	}
	else if (value > (*root)->data)
	{
		Search(&(*root)->rightChild, value);
	}
}

int main()
{
	BstNode* root = NULL;
	Insert(&root, 40);
	Insert(&root, 20);
	Insert(&root, 60);
	Insert(&root, 55);
	Insert(&root, 65);


	cout << root->data << endl;
	cout << root->leftChild->data << endl;
	cout << root->rightChild->data << endl;
	cout << root->rightChild->rightChild->data << endl;
	cout << root->rightChild->leftChild->data << endl;

	cout << "40? " << Search(&root, 40) << endl;
	cout << "60? " << Search(&root, 60) << endl;
	cout << "20? " << Search(&root, 20) << endl;
	cout << "55? " << Search(&root, 55) << endl;
	cout << "65? " << Search(&root, 65) << endl;
	cout << "5? " << Search(&root, 5) << endl;

}