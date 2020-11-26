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
	int dp[1 << N], dp_pre[1 << N];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int k = 0; k < seatsSize; ++k)
	{
		memcpy(dp_pre, dp, sizeof(dp));
		for (int i = 0; i < 1 << N; ++i)
		{
			if (dp_pre[i] == -1)
				continue;
			for (int j = mask[k]; j > 0; j = ((j - 1) & mask[k]))
			{
				if ((j & (j << 1)) == 0 && (i & (j << 1)) == 0 && (i & (j >> 1)) == 0)
				{
					int bits = bitCount(j);
					dp[j] = max(dp[j], dp_pre[i] + bits);
				}
			}
			dp[0] = max(dp[0], dp_pre[i]);
		}
	}

	int res = 0;
	for (int i = 0; i < 1 << N; ++i)
		res = max(res, dp[i]);
	return res;
}