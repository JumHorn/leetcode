#include <vector>
using namespace std;

/*
some test case integer overflow so I use unsigned int
this is permutation not shit combination
*/

class Solution
{
public:
	int combinationSum4(vector<int> &nums, int target)
	{
		vector<unsigned int> dp(target + 1);
		dp[0] = 1;
		for (int i = 0; i <= target; ++i)
		{
			for (auto n : nums)
			{
				if (i >= n)
					dp[i] += dp[i - n];
			}
		}
		return dp[target];
	}
};