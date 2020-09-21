#include <algorithm>
#include <vector>
using namespace std;

/*
dp[i]=max{dp[i-1],dp[i-2]+A}
*/

class Solution
{
public:
	int rob(vector<int> &nums)
	{
		int N = nums.size();
		if (N == 0)
			return 0;
		if (N == 1)
			return nums[0];
		int r0 = doRob(nums, 0, N - 1);
		int r1 = doRob(nums, 1, N);
		return max(r0, r1);
	}

	int doRob(vector<int> &nums, int first, int last)
	{
		vector<int> dp(last - first + 1);
		dp[0] = 0;
		dp[1] = nums[first];
		for (int i = first + 1, j = 1; i < last; ++i, ++j)
			dp[j + 1] = max(dp[j], dp[j - 1] + nums[i]);
		return dp.back();
	}
};