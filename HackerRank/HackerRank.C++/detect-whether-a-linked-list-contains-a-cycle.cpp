// https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/
#include "pch.h"

/*
  Detect loop in a linked list
  List could be empty also
  Node is defined as
*/

struct Node
{
	int data;
	struct Node *next;
};

int HasCycle(Node* head)
{
	for (Node *s = head, *f = head; s && f && f->next;) {
		s = s->next, f = f->next->next;
		if (s == f) return 1;
	}

	return 0;
}
