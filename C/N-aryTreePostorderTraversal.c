#include <stdlib.h>

//Definition for a Node.
struct Node
{
	int val;
	int numChildren;
	struct Node **children;
};

void doPostorder(struct Node *root, int *res, int *returnSize)
{
	if (!root)
		return;
	for (int i = 0; i < root->numChildren; ++i)
		doPostorder(root->children[i], res, returnSize);
	res[(*returnSize)++] = root->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *postorder(struct Node *root, int *returnSize)
{
	int *res = (int *)malloc(sizeof(int) * 10000);
	*returnSize = 0;
	doPostorder(root, res, returnSize);
	return res;
}