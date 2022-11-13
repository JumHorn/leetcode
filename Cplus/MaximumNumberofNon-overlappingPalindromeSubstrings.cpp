#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxPalindromes(string s, int k)
	{
		int N = s.size();
		vector<vector<bool>> palindrome(N, vector<bool>(N));
		for (int i = N - 1; i >= 0; --i)
		{
			for (int j = i; j < N; ++j)
				palindrome[i][j] = (i == j || (s[i] == s[j] && (i + 1 == j || palindrome[i + 1][j - 1])));
		}
		vector<int> dp(N + 1);
		for (int i = k - 1; i < N; ++i)
		{
			dp[i + 1] = dp[i];
			for (int j = i + 1 - k; j >= 0; --j)
			{
				if (palindrome[j][i])
					dp[i + 1] = max(dp[i + 1], dp[j] + 1);
			}
		}
		return dp[N];
	}
};