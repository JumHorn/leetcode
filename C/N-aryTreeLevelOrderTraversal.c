#include <stdlib.h>

// Definition for a Node.
struct Node
{
	int val;
	int numChildren;
	struct Node **children;
};

//malloc result
int **mallocRes(int (*data)[10000], int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
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
/********malloc result********/

void dfs(struct Node *root, int level, int (*staticRes)[10000], int *size, int *colSize)
{
	if (!root)
		return;
	if (level + 1 > *size)
		*size = level + 1;
	staticRes[level][colSize[level]++] = root->val;
	for (int i = 0; i < root->numChildren; ++i)
		dfs(root->children[i], level + 1, staticRes, size, colSize);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrder(struct Node *root, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[1000][10000], staticResColSize[1000];
	memset(staticResColSize, 0, sizeof(staticResColSize));
	*returnSize = 0;
	if (!root)
	{
		*returnColumnSizes = 0; //avoid attempting double free
		return root;
	}
	dfs(root, 0, staticRes, returnSize, staticResColSize);
	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}