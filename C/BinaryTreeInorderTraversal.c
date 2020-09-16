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
int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
	static struct TreeNode *stack[MAXNODE];
	static int staticRes[MAXNODE];
	int top = -1, size = 0;
	if (!root)
	{
		*returnSize = 0;
		return NULL;
	}
	struct TreeNode *cur = root;
	while (cur || top != -1)
	{
		while (cur)
		{
			stack[++top] = cur;
			cur = cur->left;
		}
		cur = stack[top--];
		staticRes[size++] = cur->val;
		cur = cur->right;
	}

	*returnSize = size;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(res, staticRes, sizeof(int) * (*returnSize));
	return res;
}