#include <stdlib.h>
#include <string.h>

int dfs(int N, int (*graph)[N], int* quiet, int* res, int index)
{
	if (res[index] != -1)
		return res[index];
	res[index] = index;
	for (int i = 0; i < N; ++i)
	{
		if (graph[index][i] == 1)
		{
			int person = dfs(N, graph, quiet, res, i);
			if (quiet[person] < quiet[res[index]])
				res[index] = person;
		}
	}
	return res[index];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* loudAndRich(int** richer, int richerSize, int* richerColSize, int* quiet, int quietSize, int* returnSize)
{
	int N = quietSize, graph[N][N];
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < richerSize; ++i)
		graph[richer[i][1]][richer[i][0]] = 1;
	*returnSize = N;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	memset(res, -1, sizeof(int) * (*returnSize));
	for (int i = 0; i < N; ++i)
		dfs(N, graph, quiet, res, i);
	return res;
}
