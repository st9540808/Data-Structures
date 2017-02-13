/**
 * Binary Tree definition
 */
#include <stdio.h>
#include "TreeNode.h"
#ifndef BT_H
#define BT_H

typedef struct BT {
	void (*BT_ctor)(struct BT *bt);
	TreeNode *root;
} BT;

void BT_init(BT *binaryTree) {}


#define BT_create() { \
	.BT_constructor = BT_init, \
	.root = NULL \
} 

#endif
