#include <stdlib.h>
#include <string.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define MAXNODE 500
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
	static struct TreeNode *stack[MAXNODE];
	static int staticRes[MAXNODE];
	int top = -1, size = 0;
	if (!root)
	{
		*returnSize = 0;
		return NULL;
	}
	stack[++top] = root;
	while (top != -1)
	{
		struct TreeNode *node = stack[top--];
		staticRes[size++] = node->val;
		if (node->right)
			stack[++top] = node->right;
		if (node->left)
			stack[++top] = node->left;
	}

	*returnSize = size;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(res, staticRes, sizeof(int) * (*returnSize));
	return res;
}