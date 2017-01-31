/**
 * Singly Linked list re-implementation
 * this will emphasize on advance operation on SLL
 */
#ifndef SLL_RE_H
#define SLL_RE_H

#include <iostream>
#include <random>
#include <chrono>
#include "ListNode_NoTemplate.h"
using namespace std;

class SLL
{
private:
	ListNode *head;
	uint32_t size;

public:
	SLL(int); // default to generate a random linked list of size 10
	~SLL();
	void insertAtFront(const int &);
	void print() const;
	void print(ListNode *) const;
	bool isSorted() const
	{
		if (this->head == NULL)
			return true;
		ListNode *currentPtr = this->head;
		while (currentPtr->next != NULL)
		{
			if (currentPtr->next->val < currentPtr->val)
				return false;
			currentPtr = currentPtr->next;
		}
		return true;
	}

	void mergeSort()
	{
		if (this->head == NULL) return;
		this->head = mergeSort(this->head);
	}

	ListNode* mergeSort(ListNode *head)
	{
		if (head->next == NULL)
			return head;
		ListNode *mid = getMiddle(head);
		ListNode *halfList = mid->next;
		mid->next = NULL;
		return merge(mergeSort(head), mergeSort(halfList));
	}

	ListNode* merge(ListNode *left, ListNode *right)
	{
		ListNode *newHead, *currentPtr;
		if (left->val < right->val)
		{
			newHead = left;
			left = left->next;
			currentPtr = newHead;
		}
		else
		{
			newHead = right;
			right = right->next;
			currentPtr = newHead;
		}

		while (left != NULL and right != NULL)
		{
			if (left->val < right ->val)
			{
				currentPtr->next = left;
				left = left->next;
			}
			else
			{
				currentPtr->next = right;
				right = right->next;
			}
			currentPtr = currentPtr->next;
		}
		currentPtr->next = (right == NULL) ? left : right;
		return newHead;
	}

	ListNode* getMiddle(ListNode *head)
	{
		ListNode *slowPtr = head, *fastPtr = head;
		while (fastPtr->next != NULL
		        and fastPtr->next->next != NULL)
		{
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next->next;
		}
		return slowPtr;
	}

	void insertionSort()   // stable sort
	{
		if (this->head == NULL or this->head->next == NULL)
			return;

		// nextPtr is always one step ahead of currentPtr
		ListNode *currentPtr = this->head, *nextPtr, *tempPtr;
		while (currentPtr->next != NULL)
		{
			nextPtr = currentPtr->next;

			if (nextPtr->val < currentPtr->val)
				if (nextPtr->val < this->head->val)
				{
					// insert in the front of the list
					currentPtr->next = nextPtr->next;
					nextPtr->next = head;
					this->head = nextPtr;
				}
				else
				{
					for (tempPtr = head;
					        tempPtr->next != currentPtr and tempPtr->next->val <= nextPtr->val;
					        tempPtr = tempPtr->next) ;
					currentPtr->next = nextPtr->next;
					nextPtr->next = tempPtr->next;
					tempPtr->next = nextPtr;
				}
			else
				currentPtr = currentPtr->next;
		}
	}
};


// methods that are less important
SLL::SLL(int inputSize = 10)
	: head(NULL), size(inputSize)
{
	// random generate linked list
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> gen(0, size * 5);

	for (uint32_t i = 0; i < size; ++i)
	{
		ListNode *newPtr = new ListNode(gen(generator));

		if (this->head == NULL)
			this->head = newPtr;
		else
		{
			newPtr->next = head;
			this->head = newPtr;
		}
	}
}

SLL::~SLL()
{
	ListNode *currentPtr = this->head, *tempPtr;
	while (currentPtr != NULL)
	{
		tempPtr = currentPtr;
		currentPtr = currentPtr->next;
		delete tempPtr;
	}
}

void SLL::insertAtFront(const int &val)
{
	ListNode *newPtr = new ListNode(val);

	if (this->head == NULL)
		this->head = newPtr;
	else
	{
		newPtr->next = head;
		this->head = newPtr;
	}
	++size;
}

void SLL::print() const
{
	ListNode *currentPtr = this->head;

	cout << "head -> ";
	while (currentPtr != NULL)
	{
		cout << currentPtr->val;
		cout << " -> ";
		currentPtr = currentPtr->next;
	}
	cout << "null\n";
}

void SLL::print(ListNode *head) const
{
	ListNode *currentPtr = head;

	cout << "head -> ";
	while (currentPtr != NULL)
	{
		cout << currentPtr->val;
		cout << " -> ";
		currentPtr = currentPtr->next;
	}
	cout << "null";
}

#endif
