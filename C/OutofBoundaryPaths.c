#include <stdlib.h>
#include <string.h>
#define MOD ((int)(1e9 + 7))

int dfs(int ***dp, int m, int n, int N, int i, int j)
{
	if (i < 0 || i >= m || j < 0 || j >= n)
		return 1;
	if (N < 0)
		return 0;
	if (dp[i][j][N] != -1)
		return dp[i][j][N];
	int res = 0;
	res = (res + dfs(dp, m, n, N - 1, i - 1, j)) % MOD;
	res = (res + dfs(dp, m, n, N - 1, i + 1, j)) % MOD;
	res = (res + dfs(dp, m, n, N - 1, i, j - 1)) % MOD;
	res = (res + dfs(dp, m, n, N - 1, i, j + 1)) % MOD;
	dp[i][j][N] = res;
	return res;
}

int findPaths(int m, int n, int N, int i, int j)
{
	int ***dp = (int ***)malloc(m * sizeof(int **));
	for (int k = 0; k < m; ++k)
	{
		dp[k] = (int **)malloc(n * sizeof(int *));
		for (int l = 0; l < n; l++)
		{
			dp[k][l] = (int *)malloc(N * sizeof(int));
			memset(dp[k][l], -1, N * sizeof(int));
		}
	}

	return dfs(dp, m, n, N - 1, i, j);
}