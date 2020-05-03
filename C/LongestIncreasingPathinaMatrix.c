#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int memdp(int **matrix, int m, int n, int i, int j, int dp[m][n])
{
	if (dp[i][j] != -1)
		return dp[i][j];
	int res = 0, tmp;
	if (i > 0 && matrix[i][j] < matrix[i - 1][j])
	{
		int tmp = 1 + memdp(matrix, m, n, i - 1, j, dp);
		res = max(res, tmp);
	}
	if (i < m - 1 && matrix[i][j] < matrix[i + 1][j])
	{
		int tmp = 1 + memdp(matrix, m, n, i + 1, j, dp);
		res = max(res, tmp);
	}
	if (j > 0 && matrix[i][j] < matrix[i][j - 1])
	{
		int tmp = 1 + memdp(matrix, m, n, i, j - 1, dp);
		res = max(res, tmp);
	}
	if (j < n - 1 && matrix[i][j] < matrix[i][j + 1])
	{
		int tmp = 1 + memdp(matrix, m, n, i, j + 1, dp);
		res = max(res, tmp);
	}
	dp[i][j] = res;
	return res;
}

int longestIncreasingPath(int **matrix, int matrixSize, int *matrixColSize)
{
	if (matrixSize == 0)
		return 0;
	int m = matrixSize, n = *matrixColSize;
	int dp[m][n];
	memset(dp, -1, sizeof(dp));
	int res = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp = memdp(matrix, m, n, i, j, dp);
			res = max(res, tmp);
		}
	}
	return res + 1;
}