#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numDecodings(string s)
	{
		int N = s.length();
		if (s.empty())
			return 0;
		if (N == 1)
			return s[0] == '0' ? 0 : 1;
		vector<int> dp(N + 1);
		dp[0] = 1;
		dp[1] = s[0] == '0' ? 0 : 1;
		for (int i = 1; i < N; ++i)
		{
			if (dp[i] != 0 && s[i] != '0')
				dp[i + 1] += dp[i];
			if (dp[i - 1] != 0 && canDecode(s, i))
				dp[i + 1] += dp[i - 1];
		}
		return dp[N];
	}

	bool canDecode(const string &s, int index)
	{
		int val = (s[index - 1] - '0') * 10 + (s[index] - '0');
		return val >= 10 && val <= 26;
	}
};