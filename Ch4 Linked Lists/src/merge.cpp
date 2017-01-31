#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
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
	// trivial case
	if (left == NULL) return right;
	else if (right == NULL) return left;

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
	currentPtr->next = (left == NULL) ? right : left;
	return newHead;
}

ListNode* mergeKLists(vector<ListNode *> &lists)
{
	if (lists.size() == 0) return NULL;
	else if (lists.size() == 1) return lists[0];

	auto left = lists.begin(),
	     right = ++lists.begin();
	while (right != lists.end())
	{
		*right = merge(*left, *right);
		++left;
		++right;
	}

	return *left;
}

int main()
{
	ListNode *list_1 = NULL,
	          *list_2 = NULL,
	           *list_3 = NULL,
	            *list_4 = NULL;
	list_1 = insertAtFront(list_1, 6);
	list_1 = insertAtFront(list_1, 3);
	list_1 = insertAtFront(list_1, 3);
	list_1 = insertAtFront(list_1, 2);

	list_2 = insertAtFront(list_2, 7);
	list_2 = insertAtFront(list_2, 5);
	list_2 = insertAtFront(list_2, 2);
	list_2 = insertAtFront(list_2, 1);

	list_3 = insertAtFront(list_3, 7);
	list_3 = insertAtFront(list_3, 6);
	list_3 = insertAtFront(list_3, 5);

	list_4 = insertAtFront(list_4, 10);
	list_4 = insertAtFront(list_4, 9);
	list_4 = insertAtFront(list_4, 4);
	list_4 = insertAtFront(list_4, 4);
	list_4 = insertAtFront(list_4, 1);

	print(list_1);
	print(list_2);
	print(list_3);
	print(list_4);

	vector<ListNode *> lists;
	lists.push_back(list_1);
	lists.push_back(list_2);
	lists.push_back(list_3);
	lists.push_back(list_4);
	ListNode *mergedList = mergeKLists(lists);
	print(mergedList);

	deleteList(mergedList);
//	deleteList(list_1);
//	deleteList(list_2);
//	deleteList(list_3);
//	deleteList(list_4);
}
