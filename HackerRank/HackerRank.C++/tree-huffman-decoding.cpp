// https://www.hackerrank.com/challenges/tree-huffman-decoding/
#include "pch.h"

#include <iostream>
#include <string>

using namespace std;

/*
The structure of the node is
*/
typedef struct node
{
	int freq;
	char data;
	node * left;
	node * right;
} node;

void decode_huff(node * root, string s)
{
	for (int i = 0; i < s.size();)
		for (node *c = root; ; c = s[i++] == '0' ? c->left : c->right)
			if (c->left == nullptr && c->right == nullptr) {
				cout << c->data;
				break;
			}
}
