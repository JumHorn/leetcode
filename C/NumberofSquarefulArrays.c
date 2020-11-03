#include <stdbool.h>
#include <string.h>

bool isSquareful(int val)
{
	int lo = 0, hi = 2e4;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (mi * mi == val)
			return true;
		if (mi * mi < val)
			lo = mi + 1;
		else
			hi = mi;
	}
	return false;
}

int numSquarefulPerms(int *A, int ASize)
{
	int graph[ASize][ASize];
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < ASize; ++i)
	{
		for (int j = i + 1; j < ASize; ++j)
		{
			if (isSquareful(A[i] + A[j]))
			{
				graph[i][j] = 1;
				graph[j][i] = 1;
			}
		}
	}

	//TSP DP
	int dp[1 << ASize][ASize];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < ASize; ++i)
		dp[1 << i][i] = 1;
	for (int mask = 1; mask < 1 << ASize; ++mask)
	{
		for (int bit = 0; bit < ASize; ++bit)
		{
			if ((1 << bit) & mask)
			{
				for (int i = 0; i < ASize; ++i)
				{
					if (graph[bit][i] == 1 && !(mask & (1 << i)))
						dp[mask | (1 << i)][i] += dp[mask][bit];
				}
			}
		}
	}

	int res = 0, mask = (1 << ASize) - 1;
	for (int i = 0; i < ASize; ++i)
		res += dp[mask][i];

	/* Divide out permutations of equal elements. */
	for (int i = 0; i < ASize; ++i)
	{
		int k = 1;
		for (int j = i + 1; j < ASize; j++)
		{
			if (A[i] == A[j])
				++k;
		}
		res /= k;
	}
	return res;
}