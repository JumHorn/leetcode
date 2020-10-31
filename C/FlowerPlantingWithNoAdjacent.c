#include <stdlib.h>
#include <string.h>

int flower(int n)
{
	int res = 0;
	while ((1 << res) & n)
		++res;
	return res + 1;
}

void plant(int (*graph)[3], int *grapColSize, int index, int *garden)
{
	int color = 0;
	for (int i = 0; i < grapColSize[index]; ++i)
	{
		if (garden[graph[index][i]] != 0)
			color |= 1 << (garden[graph[index][i]] - 1);
	}
	garden[index] = flower(color);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *gardenNoAdj(int N, int **paths, int pathsSize, int *pathsColSize, int *returnSize)
{
	*returnSize = N;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	memset(res, 0, sizeof(int) * (*returnSize));
	int graph[N][3], grapColSize[N];
	memset(grapColSize, 0, sizeof(grapColSize));
	for (int i = 0; i < pathsSize; ++i)
	{
		graph[paths[i][0] - 1][grapColSize[paths[i][0] - 1]++] = paths[i][1] - 1;
		graph[paths[i][1] - 1][grapColSize[paths[i][1] - 1]++] = paths[i][0] - 1;
	}
	for (int i = 0; i < N; ++i)
	{
		if (res[i] == 0)
			plant(graph, grapColSize, i, res);
	}
	return res;
}