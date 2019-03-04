// https://www.hackerrank.com/challenges/tree-top-view/
#include "pch.h"

#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

enum direction { center, left, right };

void top_view(node * root, direction d = direction::center) {
	if (root == nullptr)
		return;

	if (d == direction::center || d == direction::left)
		top_view(root->left, direction::left);

	cout << root->data << ' ';

	if (d == direction::center || d == direction::right)
		top_view(root->right, direction::right);
}
