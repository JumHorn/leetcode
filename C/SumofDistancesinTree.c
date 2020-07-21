#include <string.h>

void preorder(int **graph, int N, int *nodecount, int *dis, int node)
{
	for (int i = 0; i < N; ++i)
	{
		if (graph[node][i] == 1)
		{
			dis[i] = dis[node] + N - 2 * nodecount[i];
			preorder(graph, N, nodecount, dis, i);
		}
	}
}

int postorder(int **graph, int N, int *nodecount, int node)
{
	int res = 0;
	for (int i = 0; i < N; ++i)
	{
		if (graph[node][i] == 1)
		{
			graph[i][node] = 0;
			res += postorder(graph, N, nodecount, i);
			nodecount[node] += nodecount[i];
			res += nodecount[i];
		}
	}
	return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sumOfDistancesInTree(int N, int **edges, int edgesSize, int *edgesColSize, int *returnSize)
{
	int **graph = (int **)malloc(sizeof(int *) * N);
	for (int i = 0; i < N; ++i)
	{
		graph[i] = (int *)malloc(sizeof(int) * N);
		memset(graph[i], 0, sizeof(int) * N);
	}
	*returnSize = N;
	for (int i = 0; i < edgesSize; ++i)
	{
		graph[edges[i][0]][edges[i][1]] = 1;
		graph[edges[i][1]][edges[i][0]] = 1;
	}

	int nodecount[N];
	for (int i = 0; i < N; ++i)
		nodecount[i] = 1;
	int *res = (int *)malloc(sizeof(int) * N);
	res[0] = postorder(graph, N, nodecount, 0);
	preorder(graph, N, nodecount, res, 0);
	return res;
}