/**
 * Doubly Linked Lists
 */
#ifndef DOUBLYLLIST_H
#define DOUBLYLLIST_H

#include <iostream>

class DoublyLList
{
	struct Node
	{
		int val, perm;
		Node *prev;
		Node *next;
		Node(int x) : val(x), prev(nullptr), next(nullptr) {};
		Node(int x, int y) : val(x), perm(y), prev(nullptr), next(nullptr) {};
	};

private:
	Node *head;
	Node *tail; // unused for now
	uint32_t size; // unused for now

public:
	DoublyLList(int inputSize = 0)
		: head(nullptr), tail(nullptr), size(inputSize)
	{	
	}

	~DoublyLList()
	{
	}

	void insertAtHead(Node *head, Node *x)
	{
	}
};

#endif
