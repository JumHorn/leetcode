#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define max(a, b) (((a) > (b)) ? (a) : (b))

//malloc result
int **mallocRes(int (*data)[300], int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
{
	*returnSize = dataSize;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, dataColSize, sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));
		memcpy(res[i], data[i], sizeof(int) * ((*returnColumnSizes)[i]));
	}
	return res;
}

void dfs(struct TreeNode *root, int level, int (*staticRes)[300], int *size, int *colSize)
{
	if (!root)
		return;
	if (level + 1 > *size)
		*size = level + 1;
	staticRes[level][colSize[level]++] = root->val;
	dfs(root->left, level - 1, staticRes, size, colSize);
	dfs(root->right, level - 1, staticRes, size, colSize);
}

int getHeight(struct TreeNode *root)
{
	if (!root)
		return 0;
	int l = getHeight(root->left);
	int r = getHeight(root->right);
	return max(l, r) + 1;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrderBottom(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[1000][300], staticResColSize[1000];
	memset(staticResColSize, 0, sizeof(staticResColSize));
	*returnSize = 0;
	if (!root)
		return root;
	int level = getHeight(root);
	dfs(root, level - 1, staticRes, returnSize, staticResColSize);
	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}