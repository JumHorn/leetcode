#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxSum(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	static const int MOD = 1e9 + 7;
	int size = max(nums1Size, nums2Size);
	long dp[size + 1][2];
	memset(dp, 0, sizeof(dp));
	for (int i = nums1Size - 1; i >= 0; --i)
	{
		for (int j = nums2Size - 1; j >= 0; --j)
		{
			dp[i][0] = max(dp[i][0], dp[i + 1][0] + nums1[i]);
			if (nums1[i] == nums2[j])
				dp[i][0] = max(dp[i][0], dp[j + 1][1] + nums1[i]);

			dp[j][1] = max(dp[j][1], dp[j + 1][1] + nums2[j]);
			if (nums1[i] == nums2[j])
				dp[j][1] = max(dp[j][1], dp[i + 1][0] + nums2[j]);
		}
	}
	return max(dp[0][0], dp[0][1]) % MOD;
}