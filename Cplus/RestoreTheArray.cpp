#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfArrays(string s, int k)
	{
		int n = s.length();
		if (s.empty() || s[0] == '0')
			return 0;
		vector<int> dp(n + 1);
		dp[0] = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i; j >= 0; j--)
			{
				if (s[j] == '0')
					continue;
				if (i - j + 1 <= 9 && stoi(s.substr(j, i - j + 1)) <= k)
					dp[i + 1] = (dp[i + 1] + dp[j]) % MOD;
				else
					break;
			}
			if (!checkValid(dp, i))
				return 0;
		}
		return dp.back();
	}

	bool checkValid(vector<int> &dp, int index)
	{
		for (int i = index; i >= max(0, index - 9); i--)
			if (dp[i] != 0)
				return true;
		return false;
	}

private:
	static const int MOD = 1e9 + 7;
};