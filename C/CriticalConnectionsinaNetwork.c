#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int **addOneConnection(int **res, int *size, int a, int b)
{
	++*size;
	res = (int **)realloc(res, *size * sizeof(int *));
	res[*size - 1] = (int *)malloc(sizeof(int) * 2);
	res[*size - 1][0] = a;
	res[*size - 1][1] = b;
	return res;
}

void dfs(int **graph, int n, int *dsc, int *low, int parent, int at, int *time, int ***res, int *size)
{
	if (dsc[at] != 0)
		return;
	dsc[at] = low[at] = ++*time;
	for (int to = 0; to < n; ++to)
	{
		if (graph[at][to] == 0)
			continue;
		if (dsc[to] == 0)
		{
			dfs(graph, n, dsc, low, at, to, time, res, size);
			low[at] = min(low[at], low[to]);
			if (low[to] > dsc[at])
				*res = addOneConnection(*res, size, at, to);
		}
		else if (parent != to)
			low[at] = min(low[at], dsc[to]);
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **criticalConnections(int n, int **connections, int connectionsSize, int *connectionsColSize, int *returnSize, int **returnColumnSizes)
{
	int **graph = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; ++i)
	{
		graph[i] = (int *)malloc(sizeof(int) * n);
		memset(graph[i], 0, n * sizeof(int));
	}
	for (int i = 0; i < connectionsSize; ++i)
	{
		graph[connections[i][0]][connections[i][1]] = 1;
		graph[connections[i][1]][connections[i][0]] = 1;
	}
	int **res = NULL, size = 0, time = 0;
	int dsc[n], low[n];
	memset(dsc, 0, sizeof(dsc));
	memset(low, 0, sizeof(low));
	dfs(graph, n, dsc, low, -1, 0, &time, &res, &size);
	*returnSize = size;
	*returnColumnSizes = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i)
		(*returnColumnSizes)[i] = 2;
	return res;
}