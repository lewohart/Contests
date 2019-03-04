// https://www.hackerrank.com/challenges/swap-nodes-algo/
#include "pch.h"


#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

struct Node {
	int data;
	Node *left, *right;

	void transverse(int h, int k) {
		if (h % k == 0) { Node * t = left; left = right; right = t; }
		if (left != nullptr) left->transverse(h + 1, k);
		if (right != nullptr) right->transverse(h + 1, k);
	}

	template<typename Func>	void inorder(Node *n, Func f) {
		if (n == nullptr) return;
		inorder(n->left, f);
		f(n->data);
		inorder(n->right, f);
	}

	~Node() {
		delete right;
		delete left;
	}
};

struct Queue {
	struct Link { Node *n; Link *next; };
	Link *cur, *tail;
	Queue(Node *root) { tail = cur = new Link{ root, nullptr }; }
	void push(Node *n) { if (n != nullptr) tail->next = new Link{ n, nullptr }, tail = tail->next; }
	void pop() { Link *prev = cur; cur = cur->next; delete prev; }
};

int swap_nodes_algo_run() {
	int n, k;
	Node tree{ 1 };
	Queue queue(&tree);

	std::cin >> n;
	while (queue.cur) {
		std::cin >> n; queue.push(queue.cur->n->left = (n == -1 ? nullptr : new Node{ n }));
		std::cin >> n; queue.push(queue.cur->n->right = (n == -1 ? nullptr : new Node{ n }));
		queue.pop();
	}

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> k;
		tree.transverse(1, k);
		tree.inorder(&tree, [](int v) { std::cout << v << ' '; }); std::cout << std::endl;
	}
	return 0;
}
