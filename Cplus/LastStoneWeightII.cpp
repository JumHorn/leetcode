#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int lastStoneWeightII(vector<int> &stones)
	{
		int sum = accumulate(stones.begin(), stones.end(), 0);
		vector<bool> dp(sum / 2 + 1);
		dp[0] = true;
		int prefix = 0;
		for (auto stone : stones)
		{
			prefix += stone;
			for (int i = min(sum / 2, prefix); i >= stone; --i)
				dp[i] = (dp[i] || dp[i - stone]);
		}
		for (int i = sum / 2; i >= 0; --i)
		{
			if (dp[i])
				return sum - i - i;
		}
		return 0;
	}
};