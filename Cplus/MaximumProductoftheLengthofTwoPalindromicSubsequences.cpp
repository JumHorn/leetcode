#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProduct(string s)
	{
		int N = s.length();
		vector<int> dp(1 << N);
		int mask = (1 << N) - 1, res = 0;
		for (int i = 0; i < (1 << N); ++i)
			dp[i] = maxPalindromicSubsequences(s, i);
		for (int i = 0; i < (1 << N); ++i)
		{
			int len1 = dp[i];
			int len2 = dp[i ^ mask];
			res = max(res, len1 * len2);
		}
		return res;
	}

	int maxPalindromicSubsequences(string &s, int mask)
	{
		string ss;
		int N = s.length();
		for (int i = 0; i < N; ++i)
		{
			if ((1 << i) & mask)
				ss.push_back(s[i]);
		}
		return longestPalindromeSubseq(ss);
	}

	int longestPalindromeSubseq(string s)
	{
		if (s.empty())
			return 0;
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