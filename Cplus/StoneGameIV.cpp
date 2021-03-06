#include <vector>
using namespace std;

class Solution
{
public:
	bool winnerSquareGame(int n)
	{
		vector<bool> dp(n + 1);
		dp[0] = false;
		dp[1] = true;
		if (n <= 1)
			return dp[n];
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 1; j * j <= i && !dp[i]; ++j)
			{
				if (dp[i - j * j] == false)
					dp[i] = true;
			}
		}
		return dp[n];
	}
};