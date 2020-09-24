#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> largestDivisibleSubset(vector<int> &nums)
	{
		vector<int> res;
		if (nums.empty())
			return res;
		sort(nums.begin(), nums.end());
		int N = nums.size();
		vector<vector<int>> dp(N, vector<int>(2)); // dp[][0] max size dp[][1] previous index
		int maxsize = 1, maxindex = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] % nums[j] == 0 && dp[i][0] < dp[j][0] + 1)
				{
					dp[i][0] = dp[j][0] + 1;
					dp[i][1] = j;
					if (dp[i][0] > maxsize)
					{
						maxsize = dp[i][0];
						maxindex = i;
					}
				}
			}
			dp[i][0] = max(dp[i][0], 1);
		}
		while (--maxsize >= 0)
		{
			res.push_back(nums[maxindex]);
			maxindex = dp[maxindex][1];
		}
		return res;
	}
};