#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int dieSimulator(int n, vector<int>& rollMax)
	{
		static const int MOD = 1e9 + 7;
		vector<vector<int>> dp(6, vector<int>(15));
		for (int i = 0; i < 6; i++)
			dp[i][0] = 1;
		for (int i = 1; i < n; i++)
		{
			vector<vector<int>> tmp(6, vector<int>(15));
			for (int j = 0; j < 6; j++)
			{
				for (int k = 0; k < 6; k++)
				{
					for (int l = 0; l < rollMax[j]; l++)
					{
						if (j != k)
							tmp[k][0] = (tmp[k][0] + dp[j][l]) % MOD;
						else
						{
							if (l + 1 < rollMax[j])
								tmp[k][l + 1] = (tmp[k][l + 1] + dp[j][l]) % MOD;
						}
					}
				}
			}
			dp = tmp;
		}

		int res = 0;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < rollMax[i]; j++)
				res = (res + dp[i][j]) % MOD;
		}
		return res;
	}
};
