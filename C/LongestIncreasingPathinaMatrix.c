#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int memdp(int **matrix, int M, int N, int row, int col, int (*dp)[N])
{
	if (dp[row][col] != -1)
		return dp[row][col];
	int res = 0;
	//board dfs direction
	int path[5] = {-1, 0, 1, 0, -1};
	for (int k = 0; k < 4; ++k)
	{
		int x = row + path[k], y = col + path[k + 1];
		if (x >= 0 && x < M && y >= 0 && y < N && matrix[x][y] > matrix[row][col])
		{
			int longest = memdp(matrix, M, N, x, y, dp);
			res = max(res, 1 + longest);
		}
	}
	return dp[row][col] = res;
}

int longestIncreasingPath(int **matrix, int matrixSize, int *matrixColSize)
{
	if (matrixSize == 0)
		return 0;
	int res = 0, M = matrixSize, N = *matrixColSize;
	int dp[M][N];
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int longest = memdp(matrix, M, N, i, j, dp);
			res = max(res, longest);
		}
	}
	return res + 1;
}