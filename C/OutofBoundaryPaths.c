#include <stdlib.h>
#include <string.h>

#define MOD ((int)(1e9 + 7))

int dfs(int M, int N, int move, int row, int col, int (*dp)[M][N])
{
	if (row < 0 || row >= M || col < 0 || col >= N)
		return 1;
	if (move < 0)
		return 0;
	if (dp[move][row][col] != -1)
		return dp[move][row][col];
	int res = 0;
	int path[] = {-1, 0, 1, 0, -1};
	for (int k = 0; k < 4; ++k)
		res = (res + dfs(M, N, move - 1, row + path[k], col + path[k + 1], dp)) % MOD;
	dp[move][row][col] = res;
	return res;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
	int dp[maxMove][m][n];
	memset(dp, -1, sizeof(dp));
	return dfs(m, n, maxMove - 1, startRow, startColumn, dp);
}