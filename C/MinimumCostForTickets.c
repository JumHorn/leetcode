#include <string.h>

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int mincostTickets(int *days, int daysSize, int *costs, int costsSize)
{
	int N = days[daysSize - 1] + 1;
	int dp[N + 1];
	memset(dp, 0, (N + 1) * sizeof(int));
	int index = 0;
	for (int i = dp[index]; i < N; ++i)
	{
		if (i != days[index])
			dp[i + 1] = dp[i];
		else
		{
			++index;
			dp[i + 1] = dp[i] + costs[0];
			dp[i + 1] = min(dp[i + 1], dp[max(0, i + 1 - 7)] + costs[1]);
			dp[i + 1] = min(dp[i + 1], dp[max(0, i + 1 - 30)] + costs[2]);
		}
	}
	return dp[N];
}