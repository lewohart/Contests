// https://www.hackerrank.com/challenges/tree-inorder-traversal/
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

void Inorder(node *root) {
	if (root == nullptr)
		return;

	Inorder(root->left);
	cout << root->data << ' ';
	Inorder(root->right);
}
