#include <stdbool.h>
#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct
{
	struct TreeNode *stack[1000];
	int top;
} BSTIterator;

BSTIterator *bSTIteratorCreate(struct TreeNode *root)
{
	BSTIterator *iter = (BSTIterator *)malloc(sizeof(BSTIterator));
	iter->top = -1;
	while (root)
	{
		iter->stack[++iter->top] = root;
		root = root->left;
	}
	return iter;
}

/** @return the next smallest number */
int bSTIteratorNext(BSTIterator *obj)
{
	struct TreeNode *root = obj->stack[obj->top--];
	int res = root->val;
	root = root->right;
	while (root)
	{
		obj->stack[++obj->top] = root;
		root = root->left;
	}
	return res;
}

/** @return whether we have a next smallest number */
bool bSTIteratorHasNext(BSTIterator *obj)
{
	return obj->top != -1;
}

void bSTIteratorFree(BSTIterator *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);

 * bool param_2 = bSTIteratorHasNext(obj);

 * bSTIteratorFree(obj);
*/