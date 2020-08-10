#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int minDeletionSize(char** A, int ASize)
{
	int N = strlen(A[0]);
	int dp[N];
	for (int i = 0; i < N; ++i)
		dp[i] = 1;
	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			int k;
			for (k = 0; k < ASize; ++k)
			{
				if (A[k][i] < A[k][j])
					break;
			}
			if (k == ASize)
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int maxval = 0;
	for (int i = 0; i < N; ++i)
		maxval = max(maxval, dp[i]);
	return N - maxval;
}
