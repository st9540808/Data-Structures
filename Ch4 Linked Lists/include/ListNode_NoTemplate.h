#ifndef LISTNODE_NOTEMPLATE_H
#define LISTNODE_NOTEMPLATE_H
#include <cstddef>

struct ListNode
{
	int val;
	int perm; // used to check stable sort
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {};
	ListNode(int x, int y) : val(x), perm(y), next(nullptr) {};
};

#endif
