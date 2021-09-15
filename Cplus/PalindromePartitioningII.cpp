#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minCut(string s)
	{
		int N = s.length();
		vector<int> dp(N + 1);
		vector<vector<bool>> palindrome(N, vector<bool>(N));
		for (int i = N - 1; i >= 0; --i)
		{
			for (int j = i; j < N; ++j)
				palindrome[i][j] = (i == j || (s[i] == s[j] && (i + 1 == j || palindrome[i + 1][j - 1])));
		}
		dp[0] = -1;
		for (int j = 0; j < N; ++j)
		{
			dp[j + 1] = N;
			for (int i = 0; i <= j; ++i)
			{
				if (palindrome[i][j])
					dp[j + 1] = min(dp[j + 1], dp[i] + 1);
			}
		}
		return dp[N];
	}
};