/**
 * Doubly Linked Lists
 */
#ifndef DOUBLYLLIST_H
#define DOUBLYLLIST_H

#include <iostream>
#include "element.h"

class DoublyLList
{
	struct Node
	{
		element data;
		Node *prev;
		Node *next;
		Node(int x) : data(x), prev(nullptr), next(nullptr) {};
	};

private:
	Node *head;
	Node *tail; // unused for now
	uint32_t size; // unused for now

public:
	DoublyLList(int inputSize = 10) : head(nullptr), tail(nullptr), size(inputSize)
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
