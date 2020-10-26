#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

//malloc result
int **mallocRes(int **data, int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
{
	*returnSize = dataSize;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, dataColSize, sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));
	return res;
}
/********end of malloc result********/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **matrixBlockSum(int **mat, int matSize, int *matColSize, int K, int *returnSize, int **returnColumnSizes)
{
	int **res = mallocRes(mat, matSize, matColSize, returnSize, returnColumnSizes);
	int M = matSize, N = *matColSize;
	int dp[M + 1][N + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			dp[i + 1][j + 1] = mat[i][j] + dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
	}
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int a = min(M, i + K + 1), b = min(N, j + K + 1), c = max(0, i - K), d = max(0, j - K);
			res[i][j] = dp[a][b] + dp[c][d] - dp[a][d] - dp[c][b];
		}
	}
	return res;
}