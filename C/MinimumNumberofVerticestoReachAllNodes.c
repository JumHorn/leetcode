#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
	int indegree[n];
	memset(indegree, 0, sizeof(indegree));
	for (int i = 0; i < edgesSize; ++i)
		++indegree[edges[i][1]];
	int* res = (int*)malloc(sizeof(int) * n);
	*returnSize = 0;
	for (int i = 0; i < n; ++i)
	{
		if (indegree[i] == 0)
			res[(*returnSize)++] = i;
	}
	return res;
}
