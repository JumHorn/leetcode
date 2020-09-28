#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal)
	{
		int M = maxChoosableInteger, T = desiredTotal;
		if (T <= 1)
			return true;
		if (M * (M + 1) / 2 < T)
			return false;
		if (M * (M + 1) / 2 == T) //who choose last one wins
			return M & 1;
		vector<int> dp(1 << M);
		return memdp(0, M, T, dp);
	}

	bool memdp(int mask, int choose, int total, vector<int> &dp)
	{
		if (total <= 0)
			return false;
		if (dp[mask] != 0)
			return dp[mask] == 1;
		for (int i = 0; i < choose; ++i)
		{
			if ((mask & (1 << i)) == 0)
			{
				if (!memdp(mask | (1 << i), choose, total - i - 1, dp))
				{
					dp[mask] = 1;
					return true;
				}
			}
		}
		dp[mask] = -1;
		return false;
	}
};