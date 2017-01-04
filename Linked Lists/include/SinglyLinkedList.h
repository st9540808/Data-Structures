/**
 * Solution Definition
 * including all operations on Linked Lists
 */

#include <cstddef>

// definition of Singly Linked List Node
template<typename NODETYPE>
struct ListNode {
	NODETYPE val;
	ListNode<NODETYPE> *next;
	ListNode(NODETYPE x) : val(x), next(NULL) {};
};


template<typename NODETYPE>
class SinglyLinkedList
{
public:
	SinglyLinkedList(int = 10); //default list with 10 nodes
	ListNode<NODETYPE>* reverseList_Recursive();
	ListNode<NODETYPE>* reverseList_Iterative();

private:
	ListNode<NODETYPE> *head;
};
