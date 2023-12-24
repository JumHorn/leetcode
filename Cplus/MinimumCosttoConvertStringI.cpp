#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
	{
		vector<vector<long long>> dp(26, vector<long long>(26, -1));
		int N = original.size();
		for (int i = 0; i < N; ++i)
		{
			if (dp[original[i] - 'a'][changed[i] - 'a'] == -1)
				dp[original[i] - 'a'][changed[i] - 'a'] = cost[i];
			else
				dp[original[i] - 'a'][changed[i] - 'a'] = min(dp[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
		}
		for (int i = 0; i < 26; ++i)
			dp[i][i] = 0;
		for (int k = 0; k < 26; ++k)
		{
			for (int i = 0; i < 26; ++i)
			{
				for (int j = 0; j < 26; ++j)
				{
					if (dp[i][k] != -1 && dp[k][j] != -1)
					{
						if (dp[i][j] != -1)
							dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
						else
							dp[i][j] = dp[i][k] + dp[k][j];
					}
				}
			}
		}

		int M = source.size();
		long long res = 0;
		for (int i = 0; i < M; ++i)
		{
			if (dp[source[i] - 'a'][target[i] - 'a'] == -1)
				return -1;
			res += dp[source[i] - 'a'][target[i] - 'a'];
		}
		return res;
	}
};