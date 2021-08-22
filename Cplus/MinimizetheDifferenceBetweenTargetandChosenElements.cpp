#include <vector>
using namespace std;

class Solution
{
public:
	int minimizeTheDifference(vector<vector<int>> &mat, int target)
	{
		int res = INT_MAX, large = INT_MAX;
		vector<bool> dp(target + 1), dp_next(target + 1);
		dp[0] = true;
		for (auto &row : mat)
		{
			fill(dp_next.begin(), dp_next.end(), false);
			if (large != INT_MAX)
				large += *min_element(row.begin(), row.end());
			for (auto n : row)
			{
				for (int i = 0; i <= target; ++i)
				{
					if (dp[i])
					{
						if (i + n <= target)
							dp_next[i + n] = true;
						else
							large = min(large, i + n);
					}
				}
			}
			dp.swap(dp_next);
		}
		if (large != -1)
			res = large - target;
		for (int i = 0; i <= target; ++i)
		{
			if (!dp[i])
				continue;
			int diff = abs(target - i);
			if (res > diff)
				res = diff;
		}
		return res;
	}
};