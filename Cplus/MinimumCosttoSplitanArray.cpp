#include <climits>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minCost(vector<int> &nums, int k)
	{
		int N = nums.size();
		vector<int> dp(N + 1, INT_MAX);
		dp[N] = 0;
		for (int i = N - 1; i >= 0; --i)
		{
			vector<int> freq(N);
			int sum = 0;
			for (int j = i; j < N; ++j)
			{
				int count = ++freq[nums[j]];
				if (count == 2)
					sum += 2;
				else if (count > 2)
					++sum;
				dp[i] = min(dp[i], k + sum + dp[j + 1]);
			}
		}
		return dp[0];
	}
};