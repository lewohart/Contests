// https://www.hackerrank.com/challenges/reverse-a-linked-list/
#include "pch.h"

/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element
  Node is defined as
*/

struct Node
{
	int data;
	struct Node *next;
};

Node* Reverse_(Node *head)
{
	Node *p = head;
	for (Node*c = p->next; c != nullptr;) {
		Node *n = c->next;
		c->next = p;  p = c;  c = n;
	}
	head->next = nullptr;
	return p;
}

