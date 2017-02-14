/**
 * Binary Search Tree definition
 */
#ifndef BST_H
#define BST_H

#include <stdio.h>
#include "TreeNode.h"

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
