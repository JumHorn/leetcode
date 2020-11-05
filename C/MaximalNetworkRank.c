#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maximalNetworkRank(int n, int **roads, int roadsSize, int *roadsColSize)
{
	int graph[n][n], indegree[n];
	memset(graph, 0, sizeof(graph));
	memset(indegree, 0, sizeof(indegree));
	for (int i = 0; i < roadsSize; ++i)
	{
		graph[roads[i][0]][roads[i][1]] = graph[roads[i][1]][roads[i][0]] = 1;
		++indegree[roads[i][0]];
		++indegree[roads[i][1]];
	}
	int res = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
			res = max(res, indegree[i] + indegree[j] - graph[i][j]);
	}
	return res;
}