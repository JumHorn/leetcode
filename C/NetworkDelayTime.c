#include <limits.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int networkDelayTime(int** times, int timesSize, int* timesColSize, int N, int K)
{
	int dist[N + 1];
	memset(dist, 1 << 6, sizeof(dist));
	dist[K] = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < timesSize; ++j)
		{
			int u = times[j][0], v = times[j][1], w = times[j][2];
			if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
				dist[v] = dist[u] + w;
		}
	}

	int res = 0;
	for (int i = 1; i <= N; ++i)
		res = max(res, dist[i]);
	return res >= 1e5 ? -1 : res;
}
