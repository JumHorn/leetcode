#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	long long countSubarrays(vector<int> &nums, int minK, int maxK)
	{
		int N = nums.size(), pre = -1, L = -1, R = -1;
		vector<long long> dp(N + 1);
		for (int i = 0; i < N; ++i)
		{
			if (nums[i] == minK && nums[i] == maxK)
			{
				L = R = i;
				dp[i + 1] = max(0, L - pre);
			}
			if (nums[i] == minK)
			{
				L = i;
				dp[i + 1] = max(0, R - pre);
			}
			else if (nums[i] == maxK)
			{
				R = i;
				dp[i + 1] = max(0, L - pre);
			}
			else if (nums[i] > minK && nums[i] < maxK)
				dp[i + 1] = dp[i];
			else
				pre = i;
		}
		return accumulate(dp.begin(), dp.end(), 0LL);
	}
};