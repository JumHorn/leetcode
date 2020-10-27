#include <limits.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold)
{
	int graph[n][n];
	memset(graph, 1 << 5, sizeof(graph));
	for (int i = 0; i < edgesSize; ++i)
	{
		graph[edges[i][0]][edges[i][1]] = edges[i][2];
		graph[edges[i][1]][edges[i][0]] = edges[i][2];
	}
	for (int i = 0; i < n; ++i)
		graph[i][i] = 0;
	//Floyd Algorithm
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

	int res = -1, mincount = INT_MAX;
	for (int i = n - 1; i >= 0; --i)
	{
		int count = 0;
		for (int j = 0; j < n; ++j)
		{
			if (graph[i][j] <= distanceThreshold)
				++count;
		}
		if (count < mincount)
		{
			mincount = count;
			res = i;
		}
	}
	return res;
}
