#include <vector>
using namespace std;

class Solution
{
public:
	bool canCross(vector<int> &stones)
	{
		int n = stones.size();
		vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
		dp[0][1] = true;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				int k = stones[i] - stones[j];
				if (k > n || !dp[j][k])
					continue;
				dp[i][k] = true;
				if (k > 0)
					dp[i][k - 1] = true;
				if (k < n)
					dp[i][k + 1] = true;
				if (i == n - 1)
					return true;
			}
		}
		return false;
	}
};