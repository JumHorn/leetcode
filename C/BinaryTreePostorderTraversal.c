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
	struct TreeNode *pre = 0, *cur = root;
	while (top != -1 || cur)
	{
		while (cur && ((!cur->left && !cur->right) || (pre && (cur->left == pre || cur->right == pre))))
		{
			array[size++] = cur->val;
			pre = cur;
			if (top >= 0)
				cur = stack[top--];
			else
				cur = 0;
		}
		if (cur)
		{
			stack[++top] = cur;
			if (cur->right)
				stack[++top] = cur->right;
			cur = cur->left;
		}
		else
		{
			if (top >= 0)
				cur = stack[top--];
		}
	}

	*returnSize = size;
	int *res = (int *)malloc(sizeof(int) * size);
	memcpy(res, array, sizeof(int) * size);
	return res;
}