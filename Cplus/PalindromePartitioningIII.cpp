#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int palindromePartition(string s, int k)
	{
		int N = s.length();
		if (k >= N)
			return 0;
		vector<vector<int>> palindrome(N, vector<int>(N));
		for (int i = N - 1; i >= 0; --i)
		{
			for (int j = i + 1; j < N; ++j)
				palindrome[i][j] = palindrome[i + 1][j - 1] + (s[i] == s[j] ? 0 : 1);
		}

		vector<vector<int>> dp(k, vector<int>(N, INT_MAX));
		copy(palindrome[0].begin(), palindrome[0].end(), dp[0].begin());
		for (int i = 0; i < k - 1; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				for (int n = i + 1; n <= j; ++n)
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][n - 1] + palindrome[n][j]);
			}
		}
		return dp[k - 1][N - 1];
	}
};