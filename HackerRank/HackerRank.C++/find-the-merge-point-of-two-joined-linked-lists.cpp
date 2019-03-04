// https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists
#include "pch.h"

/*
   Find merge point of two linked lists
   Node is defined as
*/

struct Node
{
	int data;
	Node* next;
};

int FindMergeNode(Node *headA, Node *headB)
{
	for (Node *a = headA; a != nullptr; a = a->next)
		for (Node *b = headB; b != nullptr; b = b->next)
			if (a == b)
				return a->data;
	return 0;
}
