#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "SinglyLList.h"

class Stack : protected SinglyLList
{
public:
	Stack() : SinglyLList(0) {}

	bool isEmpty() const
	{
		return this->head == NULL;
	}

	void push(const int &pushData)
	{
		this->insertAtFront(pushData);
	}

	int top() const
	{
		return this->head->val;
	}

	uint32_t getSize()
	{
		return this->size;
	}
	
	int pop()
	{
		if (isEmpty() == true)
		{
			std::cerr << "stack is empty\n";
			return INT32_MAX;
		}

		int topValue = top();
		this->deleteAtFront();
		return topValue;
	}

	void printStack() const
	{
		ListNode *currentPtr = this->head;
	
		std::cout << "top";
		while (currentPtr != NULL)
		{
			std::cout << " -> ";
			std::cout << currentPtr->val;
			currentPtr = currentPtr->next;
		}
		std::cout << std::endl;
	}
	
	void sortStack()
	{
		if (this->size < 50)
			this->insertionSort();
		else
			this->rmergeSort();
	}
};

#endif
