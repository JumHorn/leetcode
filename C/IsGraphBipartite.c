#include <stdbool.h>
#include <string.h>

bool backTracking(int** graph, int graphSize, int* graphColSize, int* color, int node, int c)
{
	if (color[node] != 0)
		return color[node] == c;
	color[node] = c;
	for (int i = 0; i < graphColSize[node]; ++i)
	{
		if (!backTracking(graph, graphSize, graphColSize, color, graph[node][i], -c))
			return false;
	}
	return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize)
{
	int color[graphSize];
	memset(color, 0, sizeof(color));
	for (int i = 0; i < graphSize; ++i)
	{
		if (color[i] == 0 && !backTracking(graph, graphSize, graphColSize, color, i, 1))
			return false;
	}
	return true;
}
