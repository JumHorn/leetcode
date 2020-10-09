#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int orderOfLargestPlusSign(int N, int** mines, int minesSize, int* minesColSize)
{
	int hash[N * N], dp[N][N];
	memset(dp, 0, sizeof(dp));
	memset(hash, 0, sizeof(hash));
	for (int i = 0; i < minesSize; ++i)
		hash[mines[i][0] * N + mines[i][1]] = 1;
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		count = 0;
		for (int j = 0; j < N; ++j)
		{
			count = hash[i * N + j] == 1 ? 0 : count + 1;
			dp[i][j] = count;
		}
		count = 0;
		for (int j = N - 1; j >= 0; --j)
		{
			count = hash[i * N + j] == 1 ? 0 : count + 1;
			dp[i][j] = min(dp[i][j], count);
		}
	}

	int res = 0;
	for (int j = 0; j < N; ++j)
	{
		count = 0;
		for (int i = 0; i < N; ++i)
		{
			count = hash[i * N + j] == 1 ? 0 : count + 1;
			dp[i][j] = min(dp[i][j], count);
		}
		count = 0;
		for (int i = N - 1; i >= 0; --i)
		{
			count = hash[i * N + j] == 1 ? 0 : count + 1;
			dp[i][j] = min(dp[i][j], count);
			res = max(res, dp[i][j]);
		}
	}
	return res;
}
