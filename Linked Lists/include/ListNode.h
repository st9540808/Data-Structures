// definition of Singly Linked List Node

#ifndef LISTNODE_H
#define LISTNODE_H

#include <cstddef>

template<typename NODETYPE>
struct ListNode
{
	NODETYPE val;
	ListNode<NODETYPE> *next;
	ListNode(NODETYPE x) : val(x), next(NULL) {};
};

#endif
