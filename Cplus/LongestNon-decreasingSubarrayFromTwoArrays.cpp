#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxNonDecreasingLength(vector<int> &nums1, vector<int> &nums2)
	{
		int N = nums1.size(), res = 1;
		vector<vector<int>> dp(N, vector<int>(2, 1));
		for (int i = 1; i < N; ++i)
		{
			if (nums1[i] >= nums1[i - 1])
				dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
			if (nums2[i] >= nums2[i - 1])
				dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
			if (nums1[i] >= nums2[i - 1])
				dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
			if (nums2[i] >= nums1[i - 1])
				dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
			res = max({res, dp[i][0], dp[i][1]});
		}
		return res;
	}
};