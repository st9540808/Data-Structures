#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};


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

ListNode* merge(ListNode *left, ListNode *right)
{
	ListNode *newHead, *currentPtr;
	if (left->val < right->val)
		newHead = left, left = left->next;
	else
		newHead = right, right = right->next;
	currentPtr = newHead;
	
	while (left != NULL and right != NULL) {
		if (left->val < right ->val)
			currentPtr->next = left, left = left->next;
		else
			currentPtr->next = right, right = right->next;
		currentPtr = currentPtr->next;
	}
	currentPtr->next = (left == NULL) ? right : left;
	return newHead;
}

int main()
{
	ListNode *list_1 = NULL, *list_2 = NULL;
	list_1 = insertAtFront(list_1, 6);
	list_1 = insertAtFront(list_1, 3);
	list_1 = insertAtFront(list_1, 3);
	list_1 = insertAtFront(list_1, 2);

	list_2 = insertAtFront(list_2, 7);
	list_2 = insertAtFront(list_2, 5);
	list_2 = insertAtFront(list_2, 2);
	list_2 = insertAtFront(list_2, 1);
	
	print(list_1);
	print(list_2);
	
	ListNode *mergeList = merge(list_1, list_2);
	print(mergeList);
	deleteList(mergeList);

//	deleteList(list_1);
//	deleteList(list_2);
}
