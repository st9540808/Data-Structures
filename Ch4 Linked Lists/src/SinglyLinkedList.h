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
	uint32_t getSize() const;
	void print() const;
	bool isSorted() const;
	void insertionSort();

private:
	ListNode<NODETYPE> *head;
	uint32_t size;
};


template<typename NODETYPE>
SinglyLinkedList<NODETYPE>::SinglyLinkedList()
	: head(NULL), size(0) {}

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
	++size;
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
	++size;
}

template<typename NODETYPE>
void SinglyLinkedList<NODETYPE>::sortedInsert(const NODETYPE &val)
{
	ListNode<NODETYPE> *newNodePtr = new ListNode<NODETYPE>(val);

	if (head == NULL)
		head = newNodePtr;
	else if (head->val >= val)
	{
		newNodePtr->next = head;
		head = newNodePtr;
	}
	else
	{
		ListNode<NODETYPE> *tempPtr = head;
		for (; tempPtr->next != NULL and tempPtr->next->val < val;
		        tempPtr = tempPtr->next) ;
		newNodePtr->next = tempPtr->next;
		tempPtr->next = newNodePtr;
	}
	++size;
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

template<typename NODETYPE>
bool SinglyLinkedList<NODETYPE>::isEmpty() const
{
	return head == NULL;
}

template<typename NODETYPE>
uint32_t SinglyLinkedList<NODETYPE>::getSize() const
{
	return size;
}

template<typename NODETYPE>
bool SinglyLinkedList<NODETYPE>::isSorted() const
{
	ListNode<NODETYPE> *currentPtr = head;
	while (currentPtr != NULL and currentPtr->next != NULL)
	{
		if (currentPtr->val <= currentPtr->next->val)
			currentPtr = currentPtr->next;
		else
			return false;
	}
	return true;
}

void SinglyLinkedList<NODETYPE>::insertionSort() // stable sort
{
	if (head == NULL or head->next == NULL)
		return;

	// nextPtr is always one step ahead of currentPtr
	ListNode<NODETYPE> *currentPtr = head, *nextPtr, *tempPtr;
	while (currentPtr->next != NULL)
	{
		nextPtr = currentPtr->next;

		if (nextPtr->val < currentPtr->val)
			if (head->val > nextPtr->val)
			{
				// insert in the front of the list
				currentPtr->next = nextPtr->next;
				nextPtr->next = head;
				head = nextPtr;
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

#endif
