#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *pathsWithMaxScore(char **board, int boardSize, int *returnSize)
{
	static const int MOD = 1e9 + 7;
	int M = boardSize, N = strlen(board[0]);
	int dp[M][N][2];
	memset(dp, 0, sizeof(dp));
	dp[M - 1][N - 1][1] = 1;
	for (int i = M - 1; i >= 0; --i)
	{
		for (int j = N - 1; j >= 0; --j)
		{
			if (board[i][j] == 'X')
				continue;
			int path[][2] = {{1, 0}, {0, 1}, {1, 1}};
			for (int k = 0; k < 3; ++k)
			{
				int dx = i + path[k][0], dy = j + path[k][1];
				if (dx >= M || dy >= N || board[dx][dy] == 'X')
					continue;
				if (dp[dx][dy][0] > dp[i][j][0])
				{
					dp[i][j][0] = dp[dx][dy][0];
					dp[i][j][1] = dp[dx][dy][1];
				}
				else if (dp[dx][dy][0] == dp[i][j][0])
					dp[i][j][1] = (dp[i][j][1] + dp[dx][dy][1]) % MOD;
			}
			if (dp[i][j][1] != 0 && board[i][j] >= '0' && board[i][j] <= '9')
				dp[i][j][0] += board[i][j] - '0';
		}
	}

	*returnSize = 2;
	int *res = (int *)malloc(*returnSize * sizeof(int));
	memcpy(res, dp[0][0], *returnSize * sizeof(int));
	return res;
}