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
	struct TreeNode *stack[MAXNODE];
	int top = -1, array[MAXNODE], size = 0;
	if (root)
		stack[++top] = root;
	struct TreeNode *pre, *cur = root;
	while (top != -1)
	{
		pre = cur;
		cur = stack[top];
		if ((!cur->left && !cur->right) || (cur->left == pre || cur->right == pre))
		{
			array[size++] = cur->val;
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
	int *res = (int *)malloc(sizeof(int) * size);
	memcpy(res, array, sizeof(int) * size);
	return res;
}