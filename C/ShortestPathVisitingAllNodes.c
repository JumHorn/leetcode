#include <stdlib.h>
#include <string.h>

int shortestPathLength(int** graph, int graphSize, int* graphColSize)
{
	int dp[1 << graphSize][graphSize];
	memset(dp, (1 << 7) - 1, sizeof(dp));
	for (int i = 0; i < graphSize; i++)
		dp[1 << i][i] = 0;
	for (int cover = 0; cover < 1 << graphSize; ++cover)
	{
		bool repeat = true;
		while (repeat)
		{
			repeat = false;
			for (int head = 0; head < graphSize; ++head)
			{
				int dist = dp[cover][head];
				for (int i = 0; i < graphColSize[head]; ++i)
				{
					int child = graph[head][i];
					int newcover = cover | (1 << child);
					if (dist + 1 < dp[newcover][child])
					{
						dp[newcover][child] = dist + 1;
						if (cover == newcover)
							repeat = true;
					}
				}
			}
		}
	}

	int res = graphSize * graphSize;
	for (int i = 0; i < graphSize; i++)
	{
		if (dp[(1 << graphSize) - 1][i] < res)
			res = dp[(1 << graphSize) - 1][i];
	}
	return res;
}
