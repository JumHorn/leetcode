#include <stdlib.h>

//Definition for a Node.
struct Node
{
	int val;
	int numChildren;
	struct Node **children;
};

void doPreorder(struct Node *root, int *res, int *returnSize)
{
	if (!root)
		return;
	res[(*returnSize)++] = root->val;
	for (int i = 0; i < root->numChildren; ++i)
		doPreorder(root->children[i], res, returnSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *preorder(struct Node *root, int *returnSize)
{
	int *res = (int *)malloc(sizeof(int) * 10000);
	*returnSize = 0;
	doPreorder(root, res, returnSize);
	return res;
}