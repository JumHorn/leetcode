#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int bitCount(int n)
{
	int res = 0;
	for (; n != 0; n &= n - 1)
		++res;
	return res;
}

int maxStudents(char **seats, int seatsSize, int *seatsColSize)
{
	int N = *seatsColSize, mask[seatsSize];
	memset(mask, 0, sizeof(mask));
	for (int i = 0; i < seatsSize; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (seats[i][j] == '.')
				mask[i] |= 1 << j;
		}
	}
	int dp[seatsSize + 1][1 << N];
	memset(dp, 0, sizeof(dp));
	for (int k = 0; k < seatsSize; ++k)
	{
		for (int i = 0; i < 1 << N; ++i)
		{
			for (int j = 0; j < 1 << N; ++j)
			{
				if ((j & mask[k]) == j && (j & (j << 1)) == 0 && (i & (j << 1)) == 0 && (i & (j >> 1)) == 0)
					dp[k + 1][j] = max(dp[k + 1][j], dp[k][i] + bitCount(j));
			}
		}
	}

	int res = 0;
	for (int i = 0; i < 1 << N; ++i)
		res = max(res, dp[seatsSize][i]);
	return res;
}