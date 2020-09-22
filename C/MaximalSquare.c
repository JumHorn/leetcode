#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define trimin(a, b, c) (min(min(a, b), c))  //the minimum of a,b,c

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
{
	if (matrixSize == 0)
		return 0;
	int M = matrixSize, N = *matrixColSize;
	int dp[M + 1][N + 1];
	memset(dp, 0, sizeof(dp));
	int res = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (matrix[i][j] == '1')
			{
				dp[i + 1][j + 1] = trimin(dp[i][j + 1], dp[i + 1][j], dp[i][j]) + 1;
				res = max(res, dp[i + 1][j + 1]);
			}
		}
	}
	return res * res;
}
