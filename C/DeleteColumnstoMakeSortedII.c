#include <stdbool.h>
#include <string.h>

int minDeletionSize(char **A, int ASize)
{
	int N = strlen(A[0]), res = 0;
	bool sorted[ASize];
	memset(sorted, 0, sizeof(sorted));
	for (int j = 0, i = 0; j < N; ++j)
	{
		for (i = 0; i < ASize - 1; ++i)
		{
			if (!sorted[i] && A[i][j] > A[i + 1][j])
			{
				++res;
				break;
			}
		}
		if (i == ASize - 1)
		{
			for (i = 0; i < ASize - 1; ++i)
				sorted[i] = sorted[i] || A[i][j] < A[i + 1][j];
		}
	}
	return res;
}