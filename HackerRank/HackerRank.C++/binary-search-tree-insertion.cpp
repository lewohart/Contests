// https://www.hackerrank.com/challenges/binary-search-tree-insertion/
#include "pch.h"
#include "node.h"

node * insert(node * root, int value)
{
	if (root == nullptr)
		return new node{ value, nullptr, nullptr };

	if (value < root->data)
		root->left = insert(root->left, value);
	else
		root->right = insert(root->right, value);

	return root;
}
