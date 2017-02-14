/**
 * Binary Tree definition
 */
#ifndef BT_H
#define BT_H

#include <stdio.h>
#include "TreeNode.h"

typedef struct BT {
	void (*BT_ctor)(struct BT *bt);
	TreeNode *root;
} BT;

void BT_init(BT *binaryTree) {}


#define BT_create() { \
	.BT_ctor = BT_init, \
	.root = NULL \
} 

#endif
