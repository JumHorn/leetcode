#include <stdbool.h>
#include <string.h>

bool existApple(int N, int (*count)[N], int row0, int col0, int row1, int col1)
{
	return count[row1][col1] - count[row0][col1] - count[row1][col0] + count[row0][col0] != 0;
}

int ways(char **pizza, int pizzaSize, int k)
{
	static const int MOD = 1e9 + 7;
	int m = pizzaSize, n = strlen(pizza[0]);
	int count[m + 1][n + 1];
	memset(count, 0, sizeof(count));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			count[i + 1][j + 1] = (count[i][j + 1] + count[i + 1][j] - count[i][j] + (pizza[i][j] == 'A' ? 1 : 0));
	}

	int dp[m][n][k];
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	for (int c = 0; c < k - 1; ++c)
	{
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (dp[i][j][c] == 0 || !existApple(n + 1, count, i, j, m, n))
					continue;
				for (int row = i; row < m - 1; ++row)
				{
					if (existApple(n + 1, count, i, j, row + 1, n) && existApple(n + 1, count, row + 1, j, m, n))
						dp[row + 1][j][c + 1] = (dp[row + 1][j][c + 1] + dp[i][j][c]) % MOD;
				}
				for (int col = j; col < n - 1; ++col)
				{
					if (existApple(n + 1, count, i, j, m, col + 1) && existApple(n + 1, count, i, col + 1, m, n))
						dp[i][col + 1][c + 1] = (dp[i][col + 1][c + 1] + dp[i][j][c]) % MOD;
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			res = (res + dp[i][j][k - 1]) % MOD;
	}
	return res;
}