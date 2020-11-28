#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int minCost(int *houses, int housesSize, int **cost, int costSize, int *costColSize, int m, int n, int target)
{
	//INF == 1077952576
	const int BASE = 1u << 6, INF = (BASE | (BASE << 8) | (BASE << 16) | (BASE << 24));
	int dp[m][n][target + 1]; //house,color,neighboor
	memset(dp, BASE, sizeof(dp));
	//for the first house
	for (int c = 0; c < n; ++c)
	{
		if (houses[0] == c + 1)
			dp[0][c][1] = 0;
		else if (houses[0] == 0)
			dp[0][c][1] = cost[0][c];
	}

	for (int i = 1; i < m; ++i) //house
	{
		for (int c = 0; c < n; ++c) //color
		{
			for (int k = 0; k < min(target, i + 1); ++k) //neighborhood
			{
				if (houses[i] != 0 && c != houses[i] - 1)
					continue;
				int same_neighbor = dp[i - 1][c][k + 1];
				int diff_neighbor = INF;
				for (int color = 0; color < n; ++color)
				{
					if (color != c)
						diff_neighbor = min(diff_neighbor, dp[i - 1][color][k]);
				}
				int paint_cost = cost[i][c] * (houses[i] == 0 ? 1 : 0);
				dp[i][c][k + 1] = min(same_neighbor, diff_neighbor) + paint_cost;
			}
		}
	}

	int res = INF;
	for (int c = 0; c < n; ++c)
		res = min(res, dp[m - 1][c][target]);
	return res >= INF ? -1 : res;
}