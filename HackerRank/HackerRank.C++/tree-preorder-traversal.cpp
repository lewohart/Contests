// https://www.hackerrank.com/challenges/tree-preorder-traversal/
#include "pch.h"

#include <iostream>
using namespace std;

/* you only have to complete the function given below.
Node is defined as
*/

struct node
{
	int data;
	node* left;
	node* right;
};

void Preorder(node *root) {
	if (root == nullptr)
		return;

	cout << root->data << ' ';
	Preorder(root->left);
	Preorder(root->right);
}
