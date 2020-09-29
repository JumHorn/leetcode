#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestPalindromeSubseq(string s)
	{
		int N = s.length();
		vector<int> dp(N), next_dp(N);
		for (int i = N - 1; i >= 0; --i)
		{
			next_dp[i] = 1;
			for (int j = i + 1; j < N; ++j)
			{
				if (s[i] == s[j])
					next_dp[j] = dp[j - 1] + 2;
				else
					next_dp[j] = max(dp[j], next_dp[j - 1]);
			}
			dp.swap(next_dp);
		}
		return dp[N - 1];
	}
};