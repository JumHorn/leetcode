#include <stdlib.h>
#include <string.h>

#define MOD ((int)(1e9 + 7))

int dfs(int m, int n, int N, int i, int j, int (*dp)[m][n])
{
	if (i < 0 || i >= m || j < 0 || j >= n)
		return 1;
	if (N < 0)
		return 0;
	if (dp[N][i][j] != -1)
		return dp[N][i][j];
	int res = 0;
	int path[] = {-1, 0, 1, 0, -1};
	for (int k = 0; k < 4; ++k)
		res = (res + dfs(m, n, N - 1, i + path[k], j + path[k + 1], dp)) % MOD;
	dp[N][i][j] = res;
	return res;
}

int findPaths(int m, int n, int N, int i, int j)
{
	int dp[N][m][n];
	memset(dp, -1, sizeof(dp));
	return dfs(m, n, N - 1, i, j, dp);
}