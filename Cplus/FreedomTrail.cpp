#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int findRotateSteps(string ring, string key)
	{
		int M = key.length(), N = ring.length();
		vector<vector<int>> dp(M + 1, vector<int>(N));

		for (int i = M - 1; i >= 0; --i)
		{
			for (int j = 0; j < N; ++j)
			{
				dp[i][j] = INT_MAX;
				for (int k = 0; k < N; ++k)
				{
					if (ring[k] == key[i])
					{
						int step = abs(j - k);
						dp[i][j] = min(dp[i][j], dp[i + 1][k] + min(step, N - step));
					}
				}
			}
		}
		return dp[0][0] + M;
	}
};