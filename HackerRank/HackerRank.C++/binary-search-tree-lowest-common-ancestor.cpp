// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/
#include "pch.h"
#include "node.h"

node * lca(node * root, int v1, int v2)
{
	if (root == nullptr)
		return nullptr;

	if (root->data == v1 || root->data == v2)
		return root;

	node *l = lca(root->left, v1, v2);
	node *r = lca(root->right, v1, v2);

	if (r != nullptr && l != nullptr)
		return root;

	return l != nullptr ? l : r;
}

