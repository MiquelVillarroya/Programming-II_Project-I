#pragma once

#include <stdlib.h> 

// Uncomment to test
#define TEST_EX2

struct Waypoint {
	bool isExit;
	Waypoint* left;
	Waypoint* right;
	int val;
};

Waypoint* Insert(Waypoint* root, int level) {


	root = new Waypoint();
	if (level < 5) {

		level++;
		root->left = Insert(root->left, level);
		root->right = Insert(root->right, level);
	}

	return root;
}

void SetEndPoint(Waypoint* root, int level, int val) {

	if (level > 4) {
		root->isExit = true;
		root->val = val;
		return;
	}
	level++;
	if (rand() % 2 < 1) {
		SetEndPoint(root->left, level, val);
	}
	else {
		SetEndPoint(root->right, level, val);
	}
}

void GetAccessKey(Waypoint* root, int& val) {

	//TODO insert code here

	if (root->left != nullptr && root->right != nullptr)
	{
		if (val == -1) //So it only keeps iterating if key has not been found
			GetAccessKey(root->left, val);

		if (val == -1)
			GetAccessKey(root->right, val);
		
		else return;
	}
	else
	{
		if (root->isExit)
		{
			val = root->val;
		}
		return;
	}
}
