#include <string>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int strangePrinter(string s)
	{
		if (s.empty())
			return 0;
		int n = s.length();
		vector<vector<int>> dp(n, vector<int>(n, -1));
		return memdp(s, 0, n - 1, dp);
	}

	int memdp(const string &s, int i, int j, vector<vector<int>> &dp)
	{
		if (i > j)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];
		int res = memdp(s, i + 1, j, dp) + 1;
		for (int k = i + 1; k <= j; k++)
		{
			if (s[k] == s[i])
				res = min(res, memdp(s, i, k - 1, dp) + memdp(s, k + 1, j, dp));
		}
		return dp[i][j] = res;
	}
};