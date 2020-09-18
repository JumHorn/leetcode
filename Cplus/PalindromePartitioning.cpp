#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<string>> partition(string s)
	{
		if (s.empty())
			return {};
		int N = s.length();
		vector<vector<bool>> dp(N, vector<bool>(N));
		for (int l = 0; l < N; ++l)
		{
			for (int i = 0, j = l; j < N; ++i, ++j)
				dp[i][j] = s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1]);
		}
		vector<vector<string>> res;
		vector<string> instance;
		dfs(s, 0, dp, instance, res);
		return res;
	}

	void dfs(const string &s, int index, vector<vector<bool>> &dp, vector<string> &instance, vector<vector<string>> &res)
	{
		if (index >= s.length())
			res.push_back(instance);
		for (int i = index + 1; i <= (int)s.length(); ++i)
		{
			if (!dp[index][i - 1])
				continue;
			instance.push_back(s.substr(index, i - index));
			dfs(s, i, dp, instance, res);
			instance.pop_back();
		}
	}
};