// https://www.hackerrank.com/challenges/tree-level-order-traversal/
#include "pch.h"

#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

void LevelOrder(node * root) {
	struct List { node *n; List *next; };
	List *cur = new List{ root, nullptr };
	List *tail = cur;

	auto push = [&](node *n) {
		if (n != nullptr) tail->next = new List{ n, nullptr }, tail = tail->next; };

	auto pop = [&]() {
		List *prev = cur; cur = cur->next; delete prev; };

	while (cur != nullptr) {
		cout << cur->n->data << ' ';
		push(cur->n->left);
		push(cur->n->right);
		pop();
	}
}