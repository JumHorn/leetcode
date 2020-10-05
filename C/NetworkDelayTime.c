#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

void dfs(int N, int (*graph)[N + 1], int at, int time, int* delay)
{
	if (delay[at] < time)
		return;
	delay[at] = time;
	for (int i = 1; i <= N; ++i)
	{
		if (graph[at][i] != -1)
			dfs(N, graph, i, time + graph[at][i], delay);
	}
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int N, int K)
{
	int graph[N + 1][N + 1];
	memset(graph, -1, sizeof(graph));
	for (int i = 0; i < timesSize; ++i)
		graph[times[i][0]][times[i][1]] = times[i][2];
	int delay[N + 1];
	memset(delay, 1 << 6, sizeof(delay));
	dfs(N, graph, K, 0, delay);
	int res = 0;
	for (int i = 1; i <= N; ++i)
		res = max(res, delay[i]);
	return res >= 1e5 ? -1 : res;
}
