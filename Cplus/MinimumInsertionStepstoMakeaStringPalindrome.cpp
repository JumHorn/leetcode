#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minInsertions(string s)
	{
		vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
		return dfs(s, 0, s.length() - 1, dp);
	}

	int dfs(const string& s, int i, int j, vector<vector<int>>& dp)
	{
		if (i >= j)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];
		int res = 0;
		if (s[i] == s[j])
			res = dfs(s, i + 1, j - 1, dp);
		else
			res = min(dfs(s, i + 1, j, dp), dfs(s, i, j - 1, dp)) + 1;
		dp[i][j] = res;
		return res;
	}
};
