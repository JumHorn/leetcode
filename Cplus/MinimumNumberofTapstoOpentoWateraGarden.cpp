#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minTaps(int n, vector<int> &ranges)
	{
		vector<vector<int>> dp(n + 1, vector<int>(n + 1));
		int res = memdp(ranges, 0, n, dp);
		if (res >= 1000000)
			return -1;
		return res;
	}

	int memdp(vector<int> &ranges, int i, int j, vector<vector<int>> &dp)
	{
		if (i > j)
			return 0;
		if (dp[i][j] != 0)
			return dp[i][j];
		int res = 1000000;
		for (int k = i; k <= j; k++)
		{
			if (ranges[k] != 0)
			{
				res = min(res, memdp(ranges, i, k - ranges[k] - 1, dp) + memdp(ranges, k + ranges[k] + 1, j, dp) + 1);
			}
		}
		dp[i][j] = res;
		return res;
	}
};

int main()
{
	vector<int> range = {1, 0, 4, 0, 4, 1, 4, 3, 1, 1, 1, 2, 1, 4, 0, 3, 0, 3, 0, 3, 0, 5, 3, 0, 0, 1, 2, 1, 2, 4, 3, 0, 1, 0, 5, 2};
	Solution sol;
	sol.minTaps(35, range);
	return 0;
}