#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int palindromePartition(string s, int k)
	{
		int n = s.length();
		vector<vector<int>> dp(n, vector<int>(n));
		for (int i = 1; i < n; i++)
			if (s[i - 1] != s[i])
				dp[i - 1][i] = 1;
		for (int i = 2; i < n; i++)
		{
			for (int j = 0; j < n - i; j++)
				dp[j][j + i] = dp[j + 1][j + i - 1] + (s[j] == s[j + i] ? 0 : 1);
		}
		vector<vector<int>> mem(n, vector<int>(k + 1, -1));
		return recursive(dp, 0, k, mem);
	}

	int recursive(vector<vector<int>>& dp, int index, int k, vector<vector<int>>& mem)
	{
		int n = dp.size();
		if (k == 1)
			return dp[index][n - 1];
		if (mem[index][k] != -1)
			return mem[index][k];
		int res = INT_MAX;
		for (int i = index; i <= n - k; i++)
			res = min(res, dp[index][i] + recursive(dp, i + 1, k - 1, mem));
		mem[index][k] = res;
		return res;
	}
};
