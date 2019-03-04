// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/
#include "pch.h"

#include <iostream>
using namespace std;

/*
  Print elements of a linked list on console
  head pointer input could be NULL as well for empty list
  Node is defined as
*/

struct Node
{
	int data;
	struct Node *next;
};

void Print(Node *head)
{
	for (auto c = head; c != nullptr; c = c->next)
		cout << c->data << endl;
}
