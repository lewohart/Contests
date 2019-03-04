// https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/
#include "pch.h"

#include <algorithm>
using namespace std;
/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
*/

struct Node
{
	int data;
	Node *next;
	Node *prev;
};

Node* Reverse(Node* h)
{
	if (h != nullptr)
		do {
			swap(h->prev, h->next);
		}
		while (h->prev != nullptr && (h = h->prev));

	return h;
}
