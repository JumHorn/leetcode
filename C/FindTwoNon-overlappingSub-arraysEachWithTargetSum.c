#include <string.h>

/*
slide window
*/

#define min(a, b) (((a) < (b)) ? (a) : (b))

int minSumOfLengths(int* arr, int arrSize, int target)
{
	int N = arrSize, sum = 0, res = N + 1, curMinLen = N + 1;
	int dp[N];
	memset(dp, 0, sizeof(dp));
	for (int i = 0, j = 0; i < N; ++i)
	{
		sum += arr[i];
		while (sum > target)
			sum -= arr[j++];
		if (sum == target)
		{
			curMinLen = min(curMinLen, i - j + 1);
			if (j > 0)
				res = min(res, dp[j - 1] + i - j + 1);
		}
		dp[i] = curMinLen;
	}
	return res > N ? -1 : res;
}
