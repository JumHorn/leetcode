#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

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

void reverse(int *arr, int first, int last)
{
	for (; first < last; ++first, --last)
	{
		int tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
	}
}

void dfs(struct TreeNode *root, int level, int (*staticRes)[300], int *size, int *colSize)
{
	if (!root)
		return;
	if (level + 1 > *size)
		*size = level + 1;
	staticRes[level][colSize[level]++] = root->val;
	dfs(root->left, level + 1, staticRes, size, colSize);
	dfs(root->right, level + 1, staticRes, size, colSize);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **zigzagLevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[1000][300], staticResColSize[1000];
	memset(staticResColSize, 0, sizeof(staticResColSize));
	*returnSize = 0;
	if (!root)
		return root;
	dfs(root, 0, staticRes, returnSize, staticResColSize);
	for (int i = 1; i < *returnSize; i += 2)
		reverse(staticRes[i], 0, staticResColSize[i] - 1);
	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}