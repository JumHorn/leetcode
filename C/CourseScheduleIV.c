#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
Floyd–Warshall Algorithm
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* checkIfPrerequisite(int n, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
	bool graph[n][n];
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < prerequisitesSize; ++i)
		graph[prerequisites[i][0]][prerequisites[i][1]] = true;
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
		}
	}
	*returnSize = queriesSize;
	bool* res = (bool*)malloc(sizeof(bool) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		res[i] = graph[queries[i][0]][queries[i][1]];
	return res;
}
