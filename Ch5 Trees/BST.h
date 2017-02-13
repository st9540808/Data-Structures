/**
 * Binary Search Tree definition
 */
#include <stdio.h>
#include "TreeNode.h"
#ifndef BST_H
#define BST_H

typedef struct BST {
	TreeNode *root;
	void (*insert)(void);
} BST;

static void BST_insert(void)
{
	perror("what");
}

#define BST_create() { \
	.insert = BST_insert, \
	.root = NULL \
} 

#endif
