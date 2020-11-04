#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int cherryPickup(int **grid, int gridSize, int *gridColSize)
{
	int n = gridSize;
	int dp[n][n];
	memset(dp, 1u << 7, sizeof(dp)); //init to 0x80808080 a large minus number
	dp[0][0] = grid[0][0];
	for (int k = 1; k < 2 * n - 1; k++)
	{
		int dp1[n][n];
		memset(dp1, 1u << 7, sizeof(dp1));
		for (int i = max(0, k - (n - 1)); i <= min(n - 1, k); ++i)
		{
			for (int j = max(0, k - (n - 1)); j <= min(n - 1, k); ++j)
			{
				if (grid[i][k - i] == -1 || grid[j][k - j] == -1)
					continue;
				int val = grid[i][k - i];
				if (i != j)
					val += grid[j][k - j];
				for (int pi = i - 1; pi <= i; pi++)
				{
					for (int pj = j - 1; pj <= j; pj++)
					{
						if (pi >= 0 && pj >= 0)
							dp1[i][j] = max(dp1[i][j], dp[pi][pj] + val);
					}
				}
			}
		}
		memcpy(dp, dp1, sizeof(dp));
	}
	return dp[n - 1][n - 1] < 0 ? 0 : dp[n - 1][n - 1];
}