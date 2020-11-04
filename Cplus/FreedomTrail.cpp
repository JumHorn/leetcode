#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int findRotateSteps(string ring, string key)
	{
		int m = key.length(), n = ring.length();
		vector<vector<int>> dp(m + 1, vector<int>(n));

		for (int i = m - 1; i >= 0; --i)
		{
			for (int j = 0; j < n; ++j)
			{
				dp[i][j] = INT_MAX;
				for (int k = 0; k < n; k++)
				{
					if (ring[k] == key[i])
					{
						int step = abs(j - k);
						dp[i][j] = min(dp[i][j], dp[i + 1][k] + min(step, n - step));
					}
				}
			}
		}
		return dp[0][0] + m;
	}
};