#include <string.h>

double memdp(int N, int K, int r, int c, double (*dp)[N][N])
{
	if (r < 0 || r >= N || c < 0 || c >= N)
		return 0;
	if (K == 0)
		return 1;
	if (dp[K][r][c] != -1.0)
		return dp[K][r][c];
	int dr[] = {2, 2, 1, 1, -1, -1, -2, -2};
	int dc[] = {1, -1, 2, -2, 2, -2, 1, -1};
	double res = 0;
	for (int i = 0; i < 8; ++i)
		res += memdp(N, K - 1, r + dr[i], c + dc[i], dp) / 8.0;
	return dp[K][r][c] = res;
}

double knightProbability(int N, int K, int r, int c)
{
	double dp[K + 1][N][N];
	for (int k = 0; k <= K; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
				dp[k][i][j] = -1.0;
		}
	}
	return memdp(N, K, r, c, dp);
}
