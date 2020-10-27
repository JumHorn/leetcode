#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void inorder(struct TreeNode* root, int* pre, int* count, int* maxcount, int* res, int* resSize)
{
	if (!root)
		return;
	inorder(root->left, pre, count, maxcount, res, resSize);
	if (*pre != root->val)
	{
		*pre = root->val;
		*count = 0;
	}
	++*count;
	if (*count >= *maxcount)
	{
		if (*count > *maxcount)
		{
			*maxcount = *count;
			*resSize = 0;
		}
		res[(*resSize)++] = root->val;
	}
	inorder(root->right, pre, count, maxcount, res, resSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMode(struct TreeNode* root, int* returnSize)
{
	int* res = (int*)malloc(sizeof(int) * 5000);
	*returnSize = 0;
	int pre = 0, count = 0, maxcount = 0;
	inorder(root, &pre, &count, &maxcount, res, returnSize);
	return res;
}
