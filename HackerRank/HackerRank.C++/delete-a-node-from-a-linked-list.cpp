// https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/
#include "pch.h"

/*
  Delete Node at a given position in a linked list
  Node is defined as
  */
struct Node
{
	int data;
	struct Node *next;
};

Node* Delete(Node *head, int position)
{
	Node *p, *n;

	if (head == nullptr)
		return head;

	if (position == 0) {
		n = head->next;
		delete head;
		return n;
	}

	p = head;
	for (int i = 0; i < (position - 1) && p->next != nullptr; ++i)
		p = p->next;

	n = p->next;
	p->next = n->next;
	delete n;
	return head;
}
