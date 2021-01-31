#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool checkPartitioning(string s)
	{
		int N = s.length();
		vector<vector<bool>> palindrome(N, vector<bool>(N));
		for (int i = N - 1; i >= 0; --i)
		{
			for (int j = i; j < N; ++j)
				palindrome[i][j] = (i == j || (s[i] == s[j] && (i + 1 == j || palindrome[i + 1][j - 1])));
		}

		vector<vector<bool>> dp(3, vector<bool>(N));
		for (int i = 0; i < N; ++i)
			dp[0][i] = palindrome[0][i];

		for (int k = 1; k <= 2; ++k)
		{
			for (int i = k; i < N; ++i)
			{
				for (int j = i; j >= k && !dp[k][i]; --j)
				{
					if (palindrome[j][i])
						dp[k][i] = dp[k - 1][j - 1];
				}
			}
		}
		return dp[2].back();
	}
};