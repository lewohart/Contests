// https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/
#include "pch.h"

/*
  Insert Node at the begining of a linked list
  Initially head pointer argument could be NULL for empty list
  Node is defined as

return back the pointer to the head of the linked list in the below method.
*/

struct Node
{
	int data;
	struct Node *next;
};

Node* Insert(Node *head, int data)
{
	return new Node{ data, head };
}
