#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numDistinct(string s, string t)
	{
		int M = s.length(), N = t.length();
		vector<long> dp(N + 1);
		dp[0] = 1;
		for (int i = 0; i < M; ++i)
		{
			int pre = dp[0];
			for (int j = 0; j < N; j++)
			{
				int tmp = dp[j + 1];
				if (s[i] == t[j])
					dp[j + 1] += pre;
				pre = tmp;
			}
		}
		return dp[N];
	}
};