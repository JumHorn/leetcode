#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestAwesome(string s)
	{
		int N = s.length();
		vector<int> dp(1024, N);
		dp[0] = -1;
		int res = 0, mask = 0;
		for (int i = 0; i < N; ++i)
		{
			int bit = s[i] - '0';
			mask ^= 1 << bit;
			res = max(res, i - dp[mask]);
			for (int j = 0; j < 10; ++j)
				res = max(res, i - dp[mask ^ (1 << j)]);
			dp[mask] = min(dp[mask], i);
		}
		return res;
	}
};
