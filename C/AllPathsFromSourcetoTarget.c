#include <stdlib.h>

//malloc result
int **mallocRes(int (*data)[30], int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
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

void addOneResult(int (*staticRes)[30], int *size, int *colSize, int *data, int dataSize)
{
	memcpy(staticRes[*size], data, sizeof(int) * dataSize);
	colSize[(*size)++] = dataSize;
}

void dfs(int **graph, int graphSize, int *graphColSize, int node, int *instance, int instanceSize, int (*staticRes)[30], int *size, int *colSize)
{
	if (node == graphSize - 1)
	{
		addOneResult(staticRes, size, colSize, instance, instanceSize);
		return;
	}
	for (int i = 0; i < graphColSize[node]; ++i)
	{
		instance[instanceSize] = graph[node][i];
		dfs(graph, graphSize, graphColSize, graph[node][i], instance, instanceSize + 1, staticRes, size, colSize);
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **allPathsSourceTarget(int **graph, int graphSize, int *graphColSize, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[10000][30], staticResColSize[10000];
	int instance[30] = {0};
	*returnSize = 0;
	dfs(graph, graphSize, graphColSize, 0, instance, 1, staticRes, returnSize, staticResColSize);
	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}