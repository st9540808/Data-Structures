#ifndef LISTNODE_NOTEMPLATE_H
#define LISTNODE_NOTEMPLATE_H
#include <cstddef>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

#endif
