#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "SinglyLList.h"

class Stack : private SinglyLList
{
public:
	Stack() : SinglyLList(0) {}

	void push(const int &pushData)
	{
		this->insertAtFront(pushData);
	}

	int top() const
	{
		if (!isEmpty())
			return getList()->val;
		else
			return INT32_MAX;
	}

	uint32_t getStackSize()
	{
		return this->getSize();
	}
	
	int pop()
	{
		int topValue = top();
		this->deleteAtFront();
		return topValue;
	}

	void printStack() const
	{
		std::cout << "top -> ";
		this->print();
	}
	
	void sortStack()
	{
		if (this->getSize() > 40)
			this->imergeSort();
		else
			this->insertionSort();
	}

	bool isStackEmpty() {return this->isEmpty();}
};

#endif
