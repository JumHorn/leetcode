#include <stdbool.h>
#include <string.h>

bool existApple(int N, int (*count)[N], int row0, int col0, int row1, int col1)
{
	return count[row0][col0] > count[row1][col1];
}

int ways(char **pizza, int pizzaSize, int k)
{
	static const int MOD = 1e9 + 7;
	int M = pizzaSize, N = strlen(pizza[0]);
	int count[M + 1][N + 1];
	memset(count, 0, sizeof(count));
	for (int i = M - 1; i >= 0; --i)
	{
		for (int j = N - 1; j >= 0; --j)
			count[i][j] = (count[i][j + 1] + count[i + 1][j] - count[i + 1][j + 1] + (pizza[i][j] == 'A' ? 1 : 0));
	}

	int dp[M][N][k];
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	for (int c = 0; c < k - 1; ++c)
	{
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (dp[i][j][c] == 0 || !existApple(N + 1, count, i, j, M, N))
					continue;
				for (int row = i; row < M - 1; ++row)
				{
					if (existApple(N + 1, count, i, j, row + 1, j) && existApple(N + 1, count, row + 1, j, M, N))
						dp[row + 1][j][c + 1] = (dp[row + 1][j][c + 1] + dp[i][j][c]) % MOD;
				}
				for (int col = j; col < N - 1; ++col)
				{
					if (existApple(N + 1, count, i, j, i, col + 1) && existApple(N + 1, count, i, col + 1, M, N))
						dp[i][col + 1][c + 1] = (dp[i][col + 1][c + 1] + dp[i][j][c]) % MOD;
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			res = (res + dp[i][j][k - 1]) % MOD;
	}
	return res;
}