#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool preorder(struct TreeNode *root, int **voyage, int *res, int *resSize)
{
	if (!root)
		return true;
	if (root->val != *((*voyage)++))
		return false;
	if (root->left && root->left->val != **voyage)
	{
		res[(*resSize)++] = root->val;
		return preorder(root->right, voyage, res, resSize) && preorder(root->left, voyage, res, resSize);
	}
	return preorder(root->left, voyage, res, resSize) && preorder(root->right, voyage, res, resSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *flipMatchVoyage(struct TreeNode *root, int *voyage, int voyageSize, int *returnSize)
{
	int *res = (int *)malloc(sizeof(int) * voyageSize);
	*returnSize = 0;
	if (preorder(root, &voyage, res, returnSize))
		return res;
	*returnSize = 1;
	res[0] = -1;
	return res;
}