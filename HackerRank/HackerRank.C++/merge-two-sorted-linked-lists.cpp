// https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/
#include "pch.h"

/*
  Merge two sorted lists A and B as one linked list
  Node is defined as
*/
struct Node
{
	int data;
	struct Node *next;
};

Node* MergeLists(Node *headA, Node* headB)
{
	Node *a = headA, *b = headB;

	if (a == nullptr || b == nullptr)
		return (a == nullptr && b == nullptr) ? new Node() : (a > b ? a : b);

	for (;; ) {
		Node **n = (a->data < b->data) ? &a : &b;
		Node *p = *n;
		*n = (*n)->next;

		if (*n == nullptr) {
			p->next = a != nullptr ? a : b;
			break;
		}

		p->next = (a->data < b->data) ? a : b;
	}


	return (headA->data < headB->data) ? headA : headB;
}
