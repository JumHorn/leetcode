#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int memdp(int *arr, int N, int d, int index, int *dp)
{
	int left = index - 1, right = index + 1, left_max = 0, right_max = 0;
	if (dp[index] != 0)
		return dp[index];
	for (; left >= max(0, index - d) && arr[left] < arr[index]; --left)
	{
		if (dp[left] == 0)
			memdp(arr, N, d, left, dp);
		left_max = max(left_max, dp[left]);
	}
	for (; right <= min(N - 1, index + d) && arr[right] < arr[index]; ++right)
	{
		if (dp[right] == 0)
			memdp(arr, N, d, right, dp);
		right_max = max(right_max, dp[right]);
	}
	return dp[index] = 1 + max(left_max, right_max);
}

int maxJumps(int *arr, int arrSize, int d)
{
	int N = arrSize, res = 1, dp[N];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N; ++i)
	{
		int val = memdp(arr, N, d, i, dp);
		res = max(res, val);
	}
	return res;
}