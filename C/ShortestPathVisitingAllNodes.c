#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int shortestPathLength(int **graph, int graphSize, int *graphColSize)
{
	int N = graphSize, dp[1 << N][N];
	memset(dp, (1u << 7) - 1, sizeof(dp));
	for (int i = 0; i < N; ++i)
		dp[1 << i][i] = 0;
	for (int mask = 0; mask < 1 << N; ++mask)
	{
		for (bool repeat = true; repeat;)
		{
			repeat = false;
			for (int head = 0; head < N; ++head)
			{
				int dist = dp[mask][head];
				for (int i = 0; i < graphColSize[head]; ++i)
				{
					int child = graph[head][i];
					int next_mask = mask | (1 << child);
					if (dist + 1 < dp[next_mask][child])
					{
						dp[next_mask][child] = dist + 1;
						if (mask == next_mask)
							repeat = true;
					}
				}
			}
		}
	}

	int res = N * N;
	for (int i = 0; i < N; ++i)
	{
		if (dp[(1 << N) - 1][i] < res)
			res = dp[(1 << N) - 1][i];
	}
	return res;
}