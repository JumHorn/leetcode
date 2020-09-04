#include <limits.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int dp[nums1Size + 1][nums2Size + 1];
	memset(dp, 0, sizeof(dp));
	int res = INT_MIN;
	for (int i = 0; i < nums1Size; ++i)
	{
		for (int j = 0; j < nums2Size; ++j)
		{
			int val = nums1[i] * nums2[j];
			res = max(res, val);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + val);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
		}
	}
	return res <= 0 ? res : dp[nums1Size][nums2Size];
}
