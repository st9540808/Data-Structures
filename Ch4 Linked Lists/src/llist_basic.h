#include <iostream>
#include "ListNode_NoTemplate.h"
using namespace std;

void deleteList(ListNode *head);
ListNode* insertAtFront(ListNode *head, const int &val);
void print(ListNode *head);

void deleteList(ListNode *head)
{
	ListNode *currentPtr = head, *tempPtr;
	while (currentPtr != NULL)
	{
		tempPtr = currentPtr;
		currentPtr = currentPtr->next;
		delete tempPtr;
	}
}

ListNode* insertAtFront(ListNode *head, const int &val)
{
	ListNode *newPtr = new ListNode(val);

	if (head == NULL)
		head = newPtr;
	else
	{
		newPtr->next = head;
		head = newPtr;
	}
	return head;
}

void print(ListNode *head)
{
	ListNode *currentPtr = head;

	cout << "head -> ";
	while (currentPtr != NULL)
	{
		cout << currentPtr->val;
		cout << " -> ";
		currentPtr = currentPtr->next;
	}
	cout << "null\n";
}
