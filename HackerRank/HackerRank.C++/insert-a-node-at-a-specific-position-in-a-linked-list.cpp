// https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/
#include "pch.h"

/*
  Insert Node at a given position in a linked list
  head can be NULL
  First element in the linked list is at position 0
  Node is defined as
*/
struct Node
{
	int data;
	struct Node *next;
};

Node* InsertNth(Node *head, int data, int position)
{
	if (head == nullptr || position == 0)
		return new Node{ data, head };
	Node *p = head;
	for (int i = 0; i < (position - 1) && p->next != nullptr; ++i)
		p = p->next;
	p->next = new Node{ data, p->next };
	return head;
}

