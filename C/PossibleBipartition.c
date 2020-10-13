#include <stdbool.h>

bool backTracking(int N, int (*graph)[N + 1], int *color, int node, int c)
{
	if (color[node] != 0)
		return color[node] == c;
	color[node] = c;
	for (int i = 1; i <= N; ++i)
	{
		if (graph[node][i] == 1 && !backTracking(N, graph, color, i, -c))
			return false;
	}
	return true;
}

bool possibleBipartition(int N, int **dislikes, int dislikesSize, int *dislikesColSize)
{
	int color[N + 1], graph[N + 1][N + 1];
	memset(color, 0, sizeof(color));
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < dislikesSize; ++i)
	{
		graph[dislikes[i][0]][dislikes[i][1]] = 1;
		graph[dislikes[i][1]][dislikes[i][0]] = 1;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (color[i] == 0 && !backTracking(N, graph, color, i, 1))
			return false;
	}
	return true;
}