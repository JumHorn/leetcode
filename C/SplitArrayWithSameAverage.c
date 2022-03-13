#include <stdbool.h>
#include <stdlib.h>

bool splitArraySameAverage(int *A, int ASize)
{
	int sum = 0;
	for (int i = 0; i < ASize; ++i)
		sum += A[i];
	int dp[sum + 1];
	memset(dp, 0, sizeof(dp));
	dp[A[0]] = 0b10; //sum A[0] can be made up with lenth 1 in bit index
	for (int i = 1; i < ASize; ++i)
	{
		for (int j = sum - A[i]; j >= 0; --j)
		{
			if (dp[j] != 0)
				dp[j + A[i]] |= (dp[j] << 1);
		}
		dp[A[i]] |= 0b10;
	}
	for (int len = 1; len < ASize; ++len)
	{
		if (sum * len % ASize == 0 && ((1 << len) & dp[sum * len / ASize]))
			return true;
	}
	return false;
}