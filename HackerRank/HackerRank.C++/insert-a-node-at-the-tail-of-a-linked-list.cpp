// https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/
#include "pch.h"

/*
  Insert Node at the end of a linked list
  head pointer input could be NULL as well for empty list
  Node is defined as
*/

struct Node
{
	int data;
	struct Node *next;
};

Node* Insert_(Node *head, int data)
{
	Node *n = new Node{ data, nullptr };

	if (head == nullptr)
		return n;

	Node *c;
	for (c = head; c->next != nullptr; c = c->next);
	c->next = n;

	return head;
}
