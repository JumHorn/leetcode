#include <string>
using namespace std;

class Solution
{
public:
	long long numberOfWays(string s)
	{
		int N = s.length();
		long long dp0[N + 1][2], dp1[N + 1][2], dp2[N + 1][2];
		memset(dp0, 0, sizeof(dp0));
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		// vector<vector<long long>> dp0(N+1,vector<long long>(2));//index with '0','1'
		// vector<vector<long long>> dp1(N+1,vector<long long>(2));//index with '0','1'
		// vector<vector<long long>> dp2(N+1,vector<long long>(2));//index with '0','1'
		for (int i = 0; i < N; ++i)
		{
			dp0[i + 1][0] = dp0[i][0] + 1 - (s[i] - '0');
			dp0[i + 1][1] = dp0[i][1] + (s[i] - '0');
		}
		for (int i = 0; i < N; ++i)
		{
			if (s[i] == '0')
			{
				dp1[i + 1][0] = dp0[i][1] + dp1[i][0];
				dp1[i + 1][1] = dp1[i][1];
			}
			else
			{
				dp1[i + 1][1] = dp0[i][0] + dp1[i][1];
				dp1[i + 1][0] = dp1[i][0];
			}
		}

		for (int i = 0; i < N; ++i)
		{
			if (s[i] == '0')
			{
				dp2[i + 1][0] = dp1[i][1] + dp2[i][0];
				dp2[i + 1][1] = dp2[i][1];
			}
			else
			{
				dp2[i + 1][1] = dp1[i][0] + dp2[i][1];
				dp2[i + 1][0] = dp2[i][0];
			}
		}

		return dp2[N][0] + dp2[N][1];
	}
};