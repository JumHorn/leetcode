#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minCut(string s)
	{
		if (s.empty())
			return 0;
		int n = s.length();
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
				if (isPalindrome(s, j, i))
					dp[i + 1] = min(dp[i + 1], dp[j] + 1);
		}
		return dp.back() - 1;
	}

	bool isPalindrome(const string &s, int j, int i)
	{
		while (j < i)
		{
			if (s[j++] != s[i--])
				return false;
		}
		return true;
	}
};