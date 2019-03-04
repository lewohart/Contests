// https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/
#include "pch.h"

/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as
*/

struct Node
{
	int data;
	Node* next;
};

int GetNode(Node *head, int pos)
{
	Node *p = nullptr, *c;
	for (c = head; pos >= 0 && c != nullptr; c = c->next, --pos);
	for (p = head; c != nullptr; c = c->next, p = p->next);
	return p->data;
}
