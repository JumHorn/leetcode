#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
	int graph[edgesSize + 1][2], graphColSize[edgesSize + 1];
	int seen[edgesSize + 1];
	int* res = (int*)malloc(sizeof(int) * 2);
	memset(graphColSize, 0, sizeof(graphColSize));
	memset(seen, 0, sizeof(seen));
	int indegree2 = -1;
	for (int i = 0; i < edgesSize; i++)
	{
		if (seen[edges[i][0]] == 1 && seen[edges[i][1]] == 1)
			memcpy(res, edges[i], sizeof(int) * 2);
		seen[edges[i][0]] = seen[edges[i][1]] = 1;
		graph[edges[i][1]][graphColSize[edges[i][1]]++] = edges[i][0];
		if (graphColSize[edges[i][1]] > 1)
			indegree2 = edges[i][1];
	}
	if (indegree2 == -1)
		return res;
	int id = graph[indegree2][0];
	while (graphColSize[id] != 0 && id != indegree2)
		id = graph[id][0];
	if (id == indegree2)
	{
		res[0] = graph[indegree2][0];
		res[1] = indegree2;
	}
	else
	{
		res[0] = graph[indegree2][1];
		res[1] = indegree2;
	}
	*returnSize = 2;
	return res;
}
