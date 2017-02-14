#ifndef LISTNODE_H
#define LISTNODE_H

#include <cstddef>

struct ListNode
{
	const int vertex;
	const int duration;
	ListNode *link;
	ListNode(int v, int dur) : vertex(v), duration(dur), link(NULL) {}
};

#endif
