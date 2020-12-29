#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canPartitionKSubsets(vector<int> &nums, int k)
	{
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % k != 0)
			return false;
		sum /= k;
		int N = nums.size();
		vector<bool> dp(1 << N);
		vector<int> total(1 << N);
		dp[0] = true;
		for (int mask = 0; mask < 1 << N; ++mask)
		{
			for (int bit = 0; bit < N; ++bit)
			{
				if (dp[mask])
				{
					if (!(mask & 1 << bit))
					{
						int index = mask | 1 << bit;
						if (nums[bit] <= sum - total[mask] % sum)
						{
							dp[index] = true;
							total[index] = total[mask] + nums[bit];
						}
					}
				}
			}
		}
		return dp[(1 << N) - 1];
	}
};