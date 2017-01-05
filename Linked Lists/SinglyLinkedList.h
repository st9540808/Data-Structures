/**
 * Singly Linked List Definition
 * including all operations on SLL
 */

#ifndef SLL_H
#define SLL_H

#include <iostream>
#include "ListNode.h"
using namespace std;

template<typename NODETYPE>
class SinglyLinkedList
{
public:
	SinglyLinkedList();
	~SinglyLinkedList();
	void insertAtEnd(const NODETYPE &);
	void insertAtFront(const NODETYPE &);
	void sortedInsert(const NODETYPE &); //insert into a sorted linked list
	bool isEmpty() const;
	void print() const;

	void reverseList_Recursive();
	void reverseList_Iterative();
	void insertionSort();
	void mergeSort();

private:
	ListNode<NODETYPE> *head;
	bool isSorted;
};


template<typename NODETYPE>
SinglyLinkedList<NODETYPE>::SinglyLinkedList()
	: head(NULL), isSorted(false)
{
}

template<typename NODETYPE>
SinglyLinkedList<NODETYPE>::~SinglyLinkedList()
{
	ListNode<NODETYPE> *currentPtr = head, *tempPtr;
	while (currentPtr != NULL)
	{
		tempPtr = currentPtr;
		currentPtr = currentPtr->next;
		delete tempPtr;
	}
}

template<typename NODETYPE>
void SinglyLinkedList<NODETYPE>::insertAtEnd(const NODETYPE &val)
{
	ListNode<NODETYPE> *newNodePtr = new ListNode<NODETYPE>(val);
	ListNode<NODETYPE> *currentPtr = head;

	if (head == NULL)
		head = newNodePtr;
	else
	{
		while (currentPtr->next != NULL)
			currentPtr = currentPtr->next;
		currentPtr->next = newNodePtr;
	}
}

template<typename NODETYPE>
void SinglyLinkedList<NODETYPE>::insertAtFront(const NODETYPE &val)
{
	ListNode<NODETYPE> *newNodePtr = new ListNode<NODETYPE>(val);

	if (head == NULL)
		head = newNodePtr;
	else
	{
		newNodePtr->next = head;
		head = newNodePtr;
	}
}

template<typename NODETYPE>
void SinglyLinkedList<NODETYPE>::sortedInsert(const NODETYPE &val)
{
	cout << val;
}

template<typename NODETYPE>
void SinglyLinkedList<NODETYPE>::print() const
{
	ListNode<NODETYPE> *currentPtr = head;

	cout << "head -> ";
	while (currentPtr != NULL)
	{
		cout << currentPtr->val;
		cout << " -> ";
		currentPtr = currentPtr->next;
	}
	cout << "NULL\n";
}


// advance opertions on linked list
template<typename NODETYPE>
void SinglyLinkedList<NODETYPE>::insertionSort()
{
	// nextPtr is always one step ahead of currentPtr
	ListNode<NODETYPE> *currentPtr = head, *nextPtr, *tempPtr;

	if (head == NULL or head->next == NULL)
		return;

	while (currentPtr->next != NULL)
	{			
		nextPtr = currentPtr->next;
		
		if (nextPtr->val < currentPtr->val)
			if (head->val >= nextPtr->val)
			{
				// insert in the front of the list
				currentPtr->next = nextPtr->next;
				nextPtr->next = head;
				head = nextPtr;
			}
			else
			{
				for (tempPtr = head; 
						tempPtr->next != currentPtr and tempPtr->next->val < nextPtr->val;
						tempPtr = tempPtr->next) ;
				currentPtr->next = nextPtr->next;
				nextPtr->next = tempPtr->next;
				tempPtr->next = nextPtr;
			}
		else
			currentPtr = currentPtr->next;
	}
}

template<typename NODETYPE>
void SinglyLinkedList<NODETYPE>::mergeSort()
{
	ListNode<NODETYPE> *currentPtr = head;
	cout << currentPtr->next;
}

#endif
