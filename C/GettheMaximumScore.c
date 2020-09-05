#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxSum(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	int dp[nums1Size + 1][nums2Size + 1][2];
	memset(dp, 0, sizeof(dp));
	for (int i = nums1Size - 1; i >= 0; --i)
	{
		for (int j = nums2Size - 1; j >= 0; --j)
		{
			dp[i][j][0] = max(dp[i][j][0], dp[i + 1][j][0] + nums1[i]);
			if (nums1[i] == nums2[j])
				dp[i][j][0] = max(dp[i][j][0], dp[i][j + 1][1] + nums1[i]);
			dp[i][j][0] = max(dp[i][j][0], dp[i][j + 1][0]);

			dp[i][j][1] = max(dp[i][j][1], dp[i][j + 1][1] + nums2[j]);
			if (nums1[i] == nums2[j])
				dp[i][j][1] = max(dp[i][j][1], dp[i + 1][j][0] + nums2[j]);
			dp[i][j][1] = max(dp[i][j][1], dp[i + 1][j][1]);
		}
	}
	return max(dp[0][0][0], dp[0][0][1]);
}