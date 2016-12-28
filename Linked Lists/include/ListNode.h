/**
 * Definintion for siggly-linked list
 */

#include <cstddef>

template<typename NODETYPE>
struct ListNode
{
	NODETYPE val;
	ListNode<NODETYPE> *next;
	ListNode(NODETYPE x) : val(x), next(NULL) {};
};
