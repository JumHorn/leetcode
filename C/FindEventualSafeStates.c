#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool dfs(int** graph, int graphSize, int* graphColSize, int node, int* state)
{
	if (state[node] != 0)
		return state[node] == 1;
	state[node] = 2;
	for (int i = 0; i < graphColSize[node]; ++i)
	{
		if (!dfs(graph, graphSize, graphColSize, graph[node][i], state))
			return false;
	}
	state[node] = 1;
	return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize)
{
	*returnSize = 0;
	int state[graphSize];  //0 unvisited 1 safe 2 unsafe
	memset(state, 0, sizeof(state));
	int* res = (int*)malloc(sizeof(int) * graphSize);
	for (int i = 0; i < graphSize; ++i)
	{
		if (dfs(graph, graphSize, graphColSize, i, state))
			res[(*returnSize)++] = i;
	}
	return res;
}
