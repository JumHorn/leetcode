#include <stdbool.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

bool checkSquare(int M, int N, int (*dp)[N + 1], int size, int threshold)
{
	for (int i = 0; i <= M - size; ++i)
	{
		for (int j = 0; j <= N - size; ++j)
		{
			if (dp[i + size][j + size] - dp[i][j + size] - dp[i + size][j] + dp[i][j] <= threshold)
				return true;
		}
	}
	return false;
}

int maxSideLength(int **mat, int matSize, int *matColSize, int threshold)
{
	int M = matSize, N = *matColSize;
	int dp[M + 1][N + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			dp[i + 1][j + 1] = mat[i][j] - dp[i][j] + dp[i + 1][j] + dp[i][j + 1];
	}
	int lo = 1, hi = min(M, N) + 1;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (checkSquare(M, N, dp, mi, threshold))
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo - 1;
}