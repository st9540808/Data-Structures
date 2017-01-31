/**
 * Doubly Linked Lists
 */
#ifndef DLL_H
#define DLL_H

#include <iostream>
#include "element.h"
using namespace std;

class DLL 
{
	struct Node
	{
		element data;
		Node *prev;
		Node *next;
		Node(int x) : data(x), prev(NULL), next(NULL) {};
	};

private:
	Node *head;
	uint32_t size;

public:
	DLL(int inputSize = 10)
	{
	}

	~DLL()
	{
	}
};

#endif
