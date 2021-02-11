#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

//malloc result
int **mallocRes(int (*data)[1000], int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
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

void addOneResult(int (*staticRes)[1000], int *size, int *colSize, int *data, int dataSize)
{
	memcpy(staticRes[*size], data, sizeof(int) * dataSize);
	colSize[*size] = dataSize;
	++*size;
}

void preorder(struct TreeNode *root, int sum, int *instance, int instanceSize, int (*staticRes)[1000], int *size, int *colSize)
{
	if (!root)
		return;
	instance[instanceSize++] = root->val;
	if (root->left == NULL && root->right == NULL && root->val == sum)
	{
		addOneResult(staticRes, size, colSize, instance, instanceSize);
		return;
	}
	preorder(root->left, sum - root->val, instance, instanceSize, staticRes, size, colSize);
	preorder(root->right, sum - root->val, instance, instanceSize, staticRes, size, colSize);
	--instanceSize;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **pathSum(struct TreeNode *root, int sum, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[1000][1000], staticResColSize[1000];
	int instance[1000];
	*returnSize = 0;
	preorder(root, sum, instance, 0, staticRes, returnSize, staticResColSize);
	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}