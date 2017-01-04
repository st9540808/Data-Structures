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
	ListNode<NODETYPE>* getHead();
	void insertAtEnd(const int &);
	void insertAtFront(const int &);
	void sortedInsert();
	bool isEmpty() const;
	void print() const;
	
	void reverseList_Recursive();
	void reverseList_Iterative();
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
void SinglyLinkedList<NODETYPE>::insertAtEnd(const int &val)
{
	ListNode<NODETYPE> *newNodePtr = new ListNode<NODETYPE>(val);
	ListNode<NODETYPE> *currentPtr = head;
	
	if (head == NULL)
		head = newNodePtr; 
	else
	{
		while(currentPtr->next != NULL)
			currentPtr = currentPtr->next;
		currentPtr->next = newNodePtr;
	}
}

template<typename NODETYPE>
void SinglyLinkedList<NODETYPE>::insertAtFront(const int &val)
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

#endif
