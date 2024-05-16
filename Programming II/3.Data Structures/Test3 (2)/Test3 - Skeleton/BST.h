// Uncomment to perform the tests
#define TEST_3_BST

struct BSTNode {

	int value;
	BSTNode* leftChild;
	BSTNode* rightChild;
};

BSTNode* GetNewNode(int value) {
	BSTNode* newNode = new BSTNode();
	newNode->value = value;
	newNode->leftChild = nullptr;
	newNode->rightChild = nullptr;
	return newNode;
}

BSTNode* Insert(BSTNode* root, int value) {

	if (root == nullptr) {
		root = GetNewNode(value);
	}
	else if (value <= root->value) {

		root->leftChild = Insert(root->leftChild, value);
	}
	else if (value > root->value) {
		root->rightChild = Insert(root->rightChild, value);
	}

	return root;
}

int maxValue(BSTNode* root) {
	//TODO return max value of BST here
	
	if (root == nullptr) return -1;
	
	BSTNode* temp;
	temp = root;
	while (temp->rightChild != nullptr)
	{
		temp = temp->rightChild;
	}
	return temp->value;
}
#pragma once
