#include <stdbool.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int lastStoneWeightII(int* stones, int stonesSize)
{
	int sum = 0;
	for (int i = 0; i < stonesSize; ++i)
		sum += stones[i];
	bool dp[1500] = {0};
	dp[0] = true;
	int prefix = 0;
	for (int i = 0; i < stonesSize; ++i)
	{
		prefix += stones[i];
		for (int j = min(sum / 2, prefix); j >= stones[i]; --j)
			dp[j] = (dp[j] || dp[j - stones[i]]);
	}
	for (int i = sum / 2; i >= 0; --i)
	{
		if (dp[i])
			return sum - i - i;
	}
	return 0;
}
