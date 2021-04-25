#include <limits.h>
#include <string.h>

/*
状态：
dp[i][j] : nums开头取i个，末尾取j个的最大得分
k = i + j ：代表取的总数
遍历 k
状态转移：

i == 0 : 都是取末尾
dp[i][k - i] = dp[i][k - i - 1] + nums[n - k + i] * multipliers[k - 1];
i == k : 都是取前面
dp[i][k - i] = dp[i - 1][k - i] + nums[i - 1] * multipliers[k - 1];
其他情况 ： 取前面与取末尾的比较，取较大者
dp[i][k - i] = max(dp[i][k - i - 1] + nums[n - k + i] * multipliers[k - 1], dp[i - 1][k - i] + nums[i - 1] * multipliers[k - 1]);
结果 ： k == m 时, dp[i][j]的最大值
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maximumScore(int *nums, int numsSize, int *multipliers, int multipliersSize)
{
	int dp[multipliersSize + 1][multipliersSize + 1], res = INT_MIN;
	memset(dp, 0, sizeof(dp));
	for (int k = 1; k <= multipliersSize; ++k)
	{
		for (int i = 0; i <= k; ++i)
		{
			if (i == 0)
				dp[i][k - i] = dp[i][k - i - 1] + multipliers[k - 1] * nums[numsSize - k + i];
			else if (i == k)
				dp[i][k - i] = dp[i - 1][k - i] + multipliers[k - 1] * nums[i - 1];
			else
				dp[i][k - i] = max(dp[i][k - i - 1] + multipliers[k - 1] * nums[numsSize - k + i],
								   dp[i - 1][k - i] + multipliers[k - 1] * nums[i - 1]);
			if (k == multipliersSize)
				res = max(res, dp[i][k - i]);
		}
	}
	return res;
}