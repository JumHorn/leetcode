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
int *postorderTraversal(struct TreeNode *root, int *returnSize)
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
	struct TreeNode *pre = root, *cur = root;
	while (top != -1)
	{
		cur = stack[top];
		if ((!cur->left && !cur->right) || (cur->left == pre || cur->right == pre))
		{
			pre = cur;
			staticRes[size++] = cur->val;
			--top;
		}
		else
		{
			if (cur->right)
				stack[++top] = cur->right;
			if (cur->left)
				stack[++top] = cur->left;
		}
	}

	*returnSize = size;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(res, staticRes, sizeof(int) * (*returnSize));
	return res;
}