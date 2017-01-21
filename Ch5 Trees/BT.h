/**
 * Binary Tree definition
 */
#include <stdio.h>
#include "TreeNode.h"
#ifndef BT_H
#define BT_H

typedef struct BT {
	void (*BT_constructor)(struct BT *bt);
	TreeNode *root;
} BT;

void BT_init(BT *binaryTree) {
	binaryTree->root = NULL;
}


#define BT() { \
	.BT_constructor = BT_init, \
	.root = NULL \
} 

#endif
