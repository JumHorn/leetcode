#include <limits.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minFallingPathSum(int **A, int ASize, int *AColSize)
{
	int M = ASize, N = *AColSize;
	for (int i = 1; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int val = INT_MAX;
			for (int k = max(0, j - 1); k <= min(j + 1, N - 1); ++k)
				val = min(val, A[i - 1][k]);
			A[i][j] += val;
		}
	}
	int res = INT_MAX;
	for (int j = 0; j < N; ++j)
		res = min(res, A[M - 1][j]);
	return res;
}