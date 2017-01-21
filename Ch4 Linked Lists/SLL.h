/**
 * Singly Linked list re-implementation
 * this will emphasize on advance operation on SLL
 */
#include <iostream>

#ifdef LISTNODE_H
#undef LISTNODE_H
#endif
#ifdef  LISTNODE_NOTEMPALTE_H
#define LISTNODE_NOTEMPALTE_H

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

#endif
#ifdef  SLL_H
#define SLL_H

class SLL {
private:
	ListNode *head;
	uint32_t size;

public:
	SLL(int inputSize = 10) : head(NULL), size(inputSize)
	{ // random generate linked list
		
	}
		
};

#endif
