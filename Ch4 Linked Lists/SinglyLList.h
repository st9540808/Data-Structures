/**
 * Singly Linked list re-implementation
 * this will emphasize on advance operation on SinglyLList
 */
#ifndef SINGLYLLIST_RE_H
#define	SINGLYLLIST_RE_H

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "ListNode_NoTemplate.h"

class SinglyLList
{
protected:
	ListNode *head;
	uint32_t size;

public:
	SinglyLList(int); // default to generate a random linked list of size 10
	~SinglyLList();
	void insertAtFront(const int &);
	void deleteAtFront();
	void print() const;
	void print(ListNode *) const;
	bool isSorted() const;

	// adative sort using insertionsort and mergesort
	void timSort()
	{

	}

	// natural mergesort
	void naturalmergeSort()
	{
		std::vector<ListNode *> headVector(32);
		ListNode *remainingList = head;
	}

	// iterative mergesort
	void imergeSort()
	{
		std::vector<ListNode *> headVector(32);
		ListNode *remainingList = this->head;
	}

	// recursive mergesort
	void rmergeSort() 
	{
		if (this->head == nullptr) return;
		this->head = rmergeSort(this->head);
	}

	ListNode* rmergeSort(ListNode *head)
	{
		if (head->next == nullptr)
			return head;
		ListNode *mid = getMiddle(head);
		ListNode *halfList = mid->next;
		mid->next = nullptr;
		return merge_usingdummy(rmergeSort(head), rmergeSort(halfList));
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

		while (left != nullptr and right != nullptr)
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
		currentPtr->next = (right == nullptr) ? left : right;
		return newHead;
	}

	ListNode* merge_usingdummy(ListNode *left, ListNode *right)
	{
		ListNode dummy(0), *currentPtr = &dummy;
		
		while (left != nullptr and right != nullptr)
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
		currentPtr->next = (right == nullptr) ? left : right;
		return dummy.next;
	}

	ListNode* mergekLists(std::vector<ListNode *> &lists)
	{
        if (lists.empty()) return nullptr;
        auto len = lists.size();
        while (len > 1)
        {
            for (decltype(len) i = 0; i < len / 2; ++i)
                lists[i] = merge(lists[i], lists[len - 1 - i]);
            len = (len + 1) / 2;
        }
        return lists.front();
	}

	 
	// insertion sort (stable)
	void insertionSort()
	{ this->head = insertionSort(this->head);}

	ListNode* insertionSort(ListNode *head) // stable sort
	{
		if (head == nullptr or head->next == nullptr)
			return head;

		// nextPtr is always one step ahead of currentPtr
		ListNode *currentPtr = head, *nextPtr, *tempPtr;
		while (currentPtr->next != nullptr)
		{
			nextPtr = currentPtr->next;

			if (nextPtr->val < currentPtr->val)
				if (nextPtr->val < head->val)
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
		return head;
	}

private:
	ListNode* getMiddle(ListNode *head)
	{
		ListNode *slowPtr = head, *fastPtr = head;
		while (fastPtr->next != nullptr
		        and fastPtr->next->next != nullptr)
		{
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next->next;
		}
		return slowPtr;
	}
};


// methods that are less important
SinglyLList::SinglyLList(int inputSize = 10)
	: head(nullptr), size(inputSize)
{
	// random generate linked list
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> gen(0, size * 5);

	for (uint32_t i = 0; i < size; ++i)
	{
		ListNode *newPtr = new ListNode(gen(generator));

		if (this->head == nullptr)
			this->head = newPtr;
		else
		{
			newPtr->next = head;
			this->head = newPtr;
		}
	}
}

SinglyLList::~SinglyLList()
{
	ListNode *currentPtr = this->head, *tempPtr;
	while (currentPtr != nullptr)
	{
		tempPtr = currentPtr;
		currentPtr = currentPtr->next;
		delete tempPtr;
	}
}

void SinglyLList::insertAtFront(const int &val)
{
	ListNode *newPtr = new ListNode(val);

	if (this->head == nullptr)
		this->head = newPtr;
	else
	{
		newPtr->next = head;
		this->head = newPtr;
	}
	++this->size;
}

void SinglyLList::deleteAtFront()
{
	if (this->head != nullptr)
	{
		ListNode *tempPtr = this->head;
		this->head = this->head->next;
		delete tempPtr;
		--this->size;
	}
}

void SinglyLList::print() const
{
	ListNode *currentPtr = this->head;

	std::cout << "head -> ";
	while (currentPtr != nullptr)
	{
		std::cout << currentPtr->val;
		std::cout << " -> ";
		currentPtr = currentPtr->next;
	}
	std::cout << "null\n";
}

void SinglyLList::print(ListNode *head) const
{
	ListNode *currentPtr = head;

	std::cout << "head -> ";
	while (currentPtr != nullptr)
	{
		std::cout << currentPtr->val;
		std::cout << " -> ";
		currentPtr = currentPtr->next;
	}
	std::cout << "null";
}

bool SinglyLList::isSorted() const
{
	if (this->head == nullptr)
		return true;
	ListNode *currentPtr = this->head;
	while (currentPtr->next != nullptr)
	{
		if (currentPtr->next->val < currentPtr->val)
			return false;
		currentPtr = currentPtr->next;
	}
	return true;
}

#endif
