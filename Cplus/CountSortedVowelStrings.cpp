#include <vector>
using namespace std;

class Solution
{
public:
	int countVowelStrings(int n)
	{
		vector<vector<int>> dp(n + 1, vector<int>(5));
		dp[0][0] = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				for (int k = 0; k <= j; ++k)
					dp[i + 1][j] += dp[i][k];
			}
		}

		int res = 0;
		for (int i = 0; i < 5; ++i)
			res += dp[n][i];
		return res;
	}
};