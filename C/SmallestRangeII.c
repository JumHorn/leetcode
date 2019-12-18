#include <limits.h>
#include <math.h>

int dfs(int *A, int ASize, int min, int max, int K, int res)
{
	if (max - min >= res)
		return res;
	if (ASize == 0)
		return max - min;
	int tmp = 0;
	if (*A - K < min)
		tmp = dfs(A + 1, ASize - 1, *A - K, max, K, res);
	else if (*A - K > max)
		tmp = dfs(A + 1, ASize - 1, min, *A - K, K, res);
	else
		tmp = dfs(A + 1, ASize - 1, min, max, K, res);
	if (tmp < res)
		res = tmp;

	if (*A + K < min)
		tmp = dfs(A + 1, ASize - 1, *A + K, max, K, res);
	else if (*A + K > max)
		tmp = dfs(A + 1, ASize - 1, min, *A + K, K, res);
	else
		tmp = dfs(A + 1, ASize - 1, min, max, K, res);
	if (tmp < res)
		res = tmp;
	return res;
}

int smallestRangeII(int *A, int ASize, int K)
{
	int res = INT_MAX, tmp;
	res = dfs(A + 1, ASize - 1, A[0] - K, A[0] - K, K, res);
	tmp = dfs(A + 1, ASize - 1, A[0] + K, A[0] + K, K, res);
	return res < tmp ? res : tmp;
}