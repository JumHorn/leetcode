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
		vector<vector<bool>> palindrome(N, vector<bool>(N));
		for (int l = 0; l < N; ++l)
		{
			for (int i = 0, j = l; j < N; ++i, ++j)
				palindrome[i][j] = s[i] == s[j] && (j - i <= 1 || palindrome[i + 1][j - 1]);
		}
		vector<vector<vector<string>>> dp(N + 1);
		dp[0] = {{}};
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (palindrome[j][i])
				{
					for (auto &v : dp[j])
					{
						dp[i + 1].push_back(v);
						dp[i + 1].back().push_back(s.substr(j, i - j + 1));
					}
				}
			}
		}
		return dp.back();
	}
};