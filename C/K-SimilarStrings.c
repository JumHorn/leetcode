#include <limits.h>

#define swap(a, b) ((a) != (b) && ((a) ^= (b) ^= (a) ^= (b)))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int dfs(char *A, char *B, int start)
{
	int res = INT_MAX;
	while (A[start] && A[start] == B[start])
		++start;
	if (!A[start])
		return 0;
	for (int i = start + 1; A[i]; ++i)
	{
		if (B[start] == A[i] && B[i] != A[i])
		{
			swap(A[start], A[i]);
			int step = dfs(A, B, start + 1) + 1;
			res = min(res, step);
			swap(A[start], A[i]);
		}
	}
	return res == INT_MAX ? 0 : res;
}

int kSimilarity(char *A, char *B)
{
	return dfs(A, B, 0);
}