// https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/
#include "pch.h"

/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as
*/
struct Node
{
	int data;
	struct Node *next;
};

Node* RemoveDuplicates(Node *head)
{
	for (Node *c = head; c != nullptr; c = c->next) {
		while (c->next && c->data == c->next->data) {
			Node *eq = c->next;
			c->next = eq->next;
			delete eq;
		}
	}
	return head;
}
