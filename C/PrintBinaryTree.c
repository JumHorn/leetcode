#include <math.h>
#include <stdio.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define max(a, b) (((a) > (b)) ? (a) : (b))

int getTreeHeight(struct TreeNode *root)
{
	if (!root)
		return 0;
	return 1 + max(getTreeHeight(root->left), getTreeHeight(root->right));
}

void preorder(struct TreeNode *root, int left, int right, int height, char ***res)
{
	if (!root)
		return;
	int mid = (right - left) / 2 + left;
	sprintf(res[height][mid], "%d", root->val);
	preorder(root->left, left, mid, height + 1, res);
	preorder(root->right, mid, right, height + 1, res);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***printTree(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
	*returnSize = getTreeHeight(root);
	int len = pow(2, *returnSize) - 1;
	char ***res = (char ***)malloc(sizeof(char **) * (*returnSize));
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		(*returnColumnSizes)[i] = len;
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (char **)malloc(sizeof(char *) * (*returnColumnSizes)[i]);
		for (int j = 0; j < (*returnColumnSizes)[i]; ++j)
		{
			res[i][j] = (char *)malloc(sizeof(char) * 11);
			res[i][j][0] = '\0';
		}
	}
	preorder(root, 0, len, 0, res);
	return res;
}