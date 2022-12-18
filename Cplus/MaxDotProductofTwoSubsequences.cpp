#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
	{
		int max1 = *max_element(nums1.begin(), nums1.end());
		int min2 = *min_element(nums2.begin(), nums2.end());
		if (max1 < 0 && min2 > 0)
			return max1 * min2;
		int min1 = *min_element(nums1.begin(), nums1.end());
		int max2 = *max_element(nums2.begin(), nums2.end());
		if (max2 < 0 && min1 > 0)
			return max2 * min1;
		vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), INT_MIN));
		return memdp(nums1, 0, nums2, 0, dp);
	}

	int memdp(vector<int> &nums1, int index1, vector<int> &nums2, int index2, vector<vector<int>> &dp)
	{
		if (index1 >= (int)nums1.size() || index2 >= (int)nums2.size())
			return 0;
		if (dp[index1][index2] != INT_MIN)
			return dp[index1][index2];
		int res = nums1[index1] * nums2[index2] + memdp(nums1, index1 + 1, nums2, index2 + 1, dp);
		res = max(res, memdp(nums1, index1 + 1, nums2, index2, dp));
		res = max(res, memdp(nums1, index1, nums2, index2 + 1, dp));
		return dp[index1][index2] = res;
	}
};
