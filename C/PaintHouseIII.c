#include <limits.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int minCost(int *houses, int housesSize, int **cost, int costSize, int *costColSize, int m, int n, int target)
{
	int dp[m][n][target + 1];
	memset(dp, -1, sizeof(dp));
	//for the first house
	if (houses[0] != 0)
		dp[0][houses[0] - 1][1] = 0;
	else
	{
		for (int i = 0; i < n; ++i)
			dp[0][i][1] = cost[0][i];
	}

	for (int i = 1; i < m; ++i) //house
	{
		if (houses[i] != 0)
		{
			int color = houses[i] - 1;
			for (int c = 0; c < n; ++c) //color
			{
				for (int k = 0; k < target; ++k) //neighborhood
				{
					if (c != color)
					{
						if (dp[i - 1][c][k] != -1)
						{
							if (dp[i][color][k + 1] != -1)
								dp[i][color][k + 1] = min(dp[i][color][k + 1], dp[i - 1][c][k]);
							else
								dp[i][color][k + 1] = dp[i - 1][c][k];
						}
					}
					else
					{
						if (dp[i - 1][c][k + 1] != -1)
						{
							if (dp[i][color][k + 1] != -1)
								dp[i][color][k + 1] = min(dp[i][color][k + 1], dp[i - 1][c][k + 1]);
							else
								dp[i][color][k + 1] = dp[i - 1][c][k + 1];
						}
					}
				}
			}
		}
		else
		{
			for (int j = 0; j < n; ++j) //color
			{
				for (int c = 0; c < n; ++c)
				{
					for (int k = 0; k < target; ++k) //neighborhood
					{
						if (c != j)
						{
							if (dp[i - 1][c][k] != -1)
							{
								if (dp[i][j][k + 1] != -1)
									dp[i][j][k + 1] = min(dp[i][j][k + 1], dp[i - 1][c][k] + cost[i][j]);
								else
									dp[i][j][k + 1] = dp[i - 1][c][k] + cost[i][j];
							}
						}
						else
						{
							if (dp[i - 1][c][k + 1] != -1)
							{
								if (dp[i][j][k + 1] != -1)
									dp[i][j][k + 1] = min(dp[i][j][k + 1], dp[i - 1][c][k + 1] + cost[i][j]);
								else
									dp[i][j][k + 1] = dp[i - 1][c][k + 1] + cost[i][j];
							}
						}
					}
				}
			}
		}
	}

	int res = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (dp[m - 1][i][target] != -1)
			res = min(res, dp[m - 1][i][target]);
	}
	return res == INT_MAX ? -1 : res;
}