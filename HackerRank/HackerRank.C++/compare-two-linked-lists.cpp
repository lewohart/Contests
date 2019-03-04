// https://www.hackerrank.com/challenges/compare-two-linked-lists/
#include "pch.h"

/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not.
  Node is defined as
*/
struct Node
{
	int data;
	struct Node *next;
};

int CompareLists(Node *headA, Node* headB)
{
	Node *a, *b;
	for (a = headA, b = headB; a != nullptr && b != nullptr; a = a->next, b = b->next)
		if (a->data != b->data)
			return 0;
	return (a == nullptr && b == nullptr) ? 1 : 0;
}
