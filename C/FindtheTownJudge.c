#include <stdlib.h>
#include <string.h>

int findJudge(int N, int **trust, int trustSize, int *trustColSize)
{
	int degree[N + 1];
	memset(degree, 0, sizeof(degree));
	for (int i = 0; i < trustSize; ++i)
	{
		--degree[trust[i][0]];
		++degree[trust[i][1]];
	}
	for (int i = 1; i <= N; ++i)
	{
		if (degree[i] == N - 1)
			return i;
	}
	return -1;
}