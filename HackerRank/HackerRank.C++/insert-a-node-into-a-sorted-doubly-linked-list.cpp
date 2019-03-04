// https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list
#include "pch.h"

/*
	Insert Node in a doubly sorted linked list
	After each insertion, the list should be sorted
   Node is defined as
*/

struct Node
{
	int data;
	Node *next;
	Node *prev;
};

Node* SortedInsert(Node *head, int data)
{
	if (head == nullptr)
		return new Node{ data, nullptr, nullptr };

	if (data < head->data)
		return (head->prev = new Node{ data, head, nullptr });

	for (Node *p, *c = head; c != nullptr; c = c->next) {
		if (data < c->data) {
			p = c->prev;
			c->prev = p->next = new Node{ data, c, p };
			break;
		}
		if (c->next == nullptr) {
			c->next = new Node{ data, nullptr, c };
			break;
		}
	}

	return head;
}
