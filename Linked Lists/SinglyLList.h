/**
 * Singly Linked list re-implementation
 * this will emphasize on advance operation on SinglyLList
 */
#ifndef SINGLYLLIST_RE_H
#define	SINGLYLLIST_RE_H

#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>

class SinglyLList {
	struct ListNode {
		int val;
		int perm; // used to check stable sort
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {};
		ListNode(int x, int y) : val(x), perm(y), next(nullptr) {};
	};

private:
	ListNode *head;
	uint32_t size;

public:
	SinglyLList(int, int); // including range, default to generate a random linked list of size 10
	SinglyLList(const SinglyLList&); // copy constructor
	SinglyLList& operator=(SinglyLList); // copy assignment
	SinglyLList(SinglyLList&&) = default;
	SinglyLList& operator=(SinglyLList&&) = default;
	~SinglyLList();
	
	ListNode*  getList() const          { return this->head; }
	void       print() const;
	void       print(ListNode *) const;
	bool       isSorted() const;
	bool       isEmpty() const          { return head == nullptr; }
	uint32_t   getSize() const          { return size; }
	void       printPrem() const;


	// adative sort using insertionsort and merge
	void timSort(const int runSize = 15)
	{
		std::array<ListNode *, 28> paritialLists = {nullptr}; // lists of 2^i runs
		auto const beginIter = paritialLists.begin();
		auto const endIter   = paritialLists.end();
		ListNode *remainingList = this->head;
		
		while (remainingList != nullptr) {
			auto *runHead = remainingList, *runTail = remainingList;
			for (int i = 0; i < runSize and runTail->next != nullptr; ++i)
				runTail = runTail->next;
			remainingList = runTail->next;
			runTail->next = nullptr;

			if (paritialLists.front() == nullptr) {
				paritialLists.front() = this->insertionSort(runHead);
			}
			else {
				runHead = this->insertionSort(runHead);
				auto iter = beginIter;
				for (; *iter != nullptr; ++iter) {
					runHead = merge(*iter, runHead);
					*iter = nullptr;
				}
				*iter = runHead;
			}
		}
		
		for (auto iter = beginIter + 1; iter != endIter; ++iter) {
			*iter = merge(*iter, *(iter - 1));
		}
		this->head = paritialLists.back();
	}

	// natural mergesort
	void naturalmergeSort() {
		std::array<ListNode *, 31> paritialLists = {nullptr}; // lists of 2^i runs
		auto const beginIter = paritialLists.begin(), endIter = paritialLists.end();
		ListNode *remainingList = this->head;
		
		while (remainingList != nullptr) {
			auto *runHead = remainingList, *runTail = remainingList;
			while (runTail->next != nullptr and runTail->val <= runTail->next->val)
				runTail = runTail->next;
			remainingList = runTail->next;
			runTail->next = nullptr;

			if (paritialLists.front() == nullptr) {
				paritialLists.front() = runHead;
			}
			else {
				auto iter = beginIter;
				for (; *iter != nullptr; ++iter) {
					runHead = merge(*iter, runHead);
					*iter = nullptr;
				}
				*iter = runHead;
			}
		}
		
		for (auto iter = beginIter + 1; iter != endIter; ++iter)
			*iter = merge(*iter, *(iter - 1));
		this->head = paritialLists.back();
	}

	// iterative mergesort, it's capable of sorting 2^31-1 nodes (arround 34.36 GB)
	void imergeSort() {
		std::array<ListNode *, 31> paritialLists = {nullptr}; // lists of 2^i nodes
		auto const beginIter = paritialLists.begin(), endIter = paritialLists.end();
		ListNode *remainingList = this->head;
		
		while (remainingList != nullptr) {
			auto *result = remainingList;
			remainingList = remainingList->next;
			result->next = nullptr;
			
			if (paritialLists.front() == nullptr) {
				paritialLists.front() = result;
			}
			else {
				auto iter = beginIter;
				for (; *iter != nullptr; ++iter) {
					result = merge(*iter, result);
					*iter = nullptr;
				}
				*iter = result;
			}
		}
		
		for (auto iter = beginIter + 1; iter != endIter; ++iter)
			*iter = merge(*iter, *(iter - 1));
		this->head = paritialLists.back();
	}

	// recursive mergesort
	void rmergeSort() {
		this->head = (this->head == nullptr) ? nullptr : rmergeSort(this->head);
	}

	ListNode* rmergeSort(ListNode *head) {
		if (head->next == nullptr)
			return head;
		ListNode *mid = getMiddle(head);
		ListNode *halfList = mid->next;
		mid->next = nullptr;
		return merge(rmergeSort(head), rmergeSort(halfList));
	}

	ListNode* merge(ListNode *left, ListNode *right) {
		if (left == nullptr) return right;
		else if (right == nullptr) return left;
		
		static ListNode dummy(0);
		ListNode *currentPtr = &dummy;
		while (left != nullptr and right != nullptr)
			if (left->val <= right->val) {
				currentPtr->next = left;
				left = left->next;
				currentPtr = currentPtr->next;
			}
			else {
				currentPtr->next = right;
				right = right->next;
				currentPtr = currentPtr->next;
			}

		currentPtr->next = (right == nullptr) ? left : right;
		return dummy.next;
	}

	ListNode* mergekLists(std::vector<ListNode *> &lists) {
		if (lists.empty()) return nullptr;
		auto len = lists.size();
		while (len > 1) {
			for (decltype(len) i = 0; i < len / 2; ++i)
				lists[i] = merge(lists[i], lists[len - 1 - i]);
			len = (len + 1) / 2;
		}
		return lists.front();
	}

	ListNode* getMiddle(ListNode *head) {
		ListNode *slowPtr = head, *fastPtr = head;
		while (fastPtr->next != nullptr
		        and fastPtr->next->next != nullptr) {
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next->next;
		}
		return slowPtr;
	}
	 
	// insertion sort (stable)
	void insertionSort() {
		this->head = insertionSort(this->head);
	}

	ListNode* insertionSort(ListNode *head) { // stable sort
		if (head == nullptr or head->next == nullptr)
			return head;

		// nextPtr is always one step ahead of currentPtr
		ListNode *currentPtr = head, *nextPtr, *tempPtr;
		while (currentPtr->next != nullptr) {
			nextPtr = currentPtr->next;

			if (nextPtr->val < currentPtr->val)
				if (nextPtr->val < head->val) {
					// insert in the front of the list
					currentPtr->next = nextPtr->next;
					nextPtr->next = head;
					head = nextPtr;
				}
				else {
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
};


// methods that are less important
SinglyLList::SinglyLList(int inputSize = 0, int range = 0)
	: head(nullptr)
	, size(inputSize)
{
	if (range == 0) range = inputSize;
	// random generate linked list
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> gen(0, range);

	for (uint32_t i = 0; i < size; ++i) {
		ListNode *newPtr = new ListNode(gen(generator), size - i);

		if (this->head == nullptr) {
			this->head = newPtr;
		}
		else {
			newPtr->next = head;
			this->head = newPtr;
		}
	}
}

SinglyLList::SinglyLList(const SinglyLList& rhs)
	: head(nullptr)
	, size(rhs.size)
{
	if (this != &rhs) {
		ListNode *const *rhsPtr = &rhs.head;
		ListNode **currentPtr   = &this->head;
		
		while (*rhsPtr != nullptr) {
			ListNode *newNode
				= new ListNode((*rhsPtr)->val, (*rhsPtr)->perm);
			*currentPtr = newNode;
			rhsPtr = &(*rhsPtr)->next;
			currentPtr = &(*currentPtr)->next;
		}
	}
}

SinglyLList& SinglyLList::operator=(SinglyLList rhs_copy)
{
	std::swap(this->head, rhs_copy.head);
	std::swap(this->size, rhs_copy.size);
	return *this;
}

SinglyLList::~SinglyLList()
{
	ListNode *currentPtr = this->head, *tempPtr;
	while (currentPtr != nullptr) {
		tempPtr = currentPtr;
		currentPtr = currentPtr->next;
		delete tempPtr;
	}
}

void SinglyLList::print() const
{
	print(this->head);
}

void SinglyLList::print(ListNode *head) const
{
	ListNode *currentPtr = head;

	while (currentPtr != nullptr) {
		std::cout << currentPtr->val;
		std::cout << " -> ";
		currentPtr = currentPtr->next;
	}
	std::cout << "null\n";
}

bool SinglyLList::isSorted() const
{
	if (this->head == nullptr)
		return true;
	ListNode *currentPtr = this->head;
	while (currentPtr->next != nullptr) {
		if (currentPtr->next->val < currentPtr->val)
			return false;
		currentPtr = currentPtr->next;
	}
	return true;
}

void SinglyLList::printPrem() const
{
	ListNode *currentPtr = this->head;

	while (currentPtr != nullptr) {
		std::cout << currentPtr->perm;
		std::cout << " -> ";
		currentPtr = currentPtr->next;
	}
	std::cout << "null\n";
}

#endif
