#include <string>
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
		for (int i = N - 1; i >= 0; --i)
		{
			for (int j = i; j < N; ++j)
				palindrome[i][j] = (i == j || (s[i] == s[j] && (i + 1 == j || palindrome[i + 1][j - 1])));
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