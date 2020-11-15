#include <string.h>

/*
dp[row1][row2] for k is the layer
then col1=k-row1 col2=k-row2
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int cherryPickup(int **grid, int gridSize, int *gridColSize)
{
	int N = gridSize;
	int dp[N][N];
	memset(dp, 1u << 7, sizeof(dp)); //init to 0x80808080 a large minus number
	dp[0][0] = grid[0][0];
	for (int k = 1; k < 2 * N - 1; ++k)
	{
		int next_dp[N][N];
		memset(next_dp, 1u << 7, sizeof(next_dp));
		for (int i = max(0, k - (N - 1)); i <= min(N - 1, k); ++i)
		{
			for (int j = max(0, k - (N - 1)); j <= min(N - 1, k); ++j)
			{
				if (grid[i][k - i] == -1 || grid[j][k - j] == -1)
					continue;
				int val = grid[i][k - i];
				if (i != j)
					val += grid[j][k - j];
				for (int pi = i - 1; pi <= i; ++pi)
				{
					for (int pj = j - 1; pj <= j; ++pj)
					{
						if (pi >= 0 && pj >= 0)
							next_dp[i][j] = max(next_dp[i][j], dp[pi][pj] + val);
					}
				}
			}
		}
		memcpy(dp, next_dp, sizeof(dp));
	}
	return max(0, dp[N - 1][N - 1]);
}