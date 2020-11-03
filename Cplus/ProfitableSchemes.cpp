#include <cstring>
#include <vector>
using namespace std;

class Solution
{
public:
	int profitableSchemes(int G, int P, vector<int> &group, vector<int> &profit)
	{
		int N = group.size(), res = 0;
		vector<vector<int>> dp(G + 1, vector<int>(P + 1));
		dp[0][0] = 1;
		for (int i = 0; i < N; ++i)
		{
			for (int k = G - group[i]; k >= 0; k--)
			{
				for (int j = 0; j <= P; j++)
					dp[k + group[i]][min(j + profit[i], P)] = (dp[k + group[i]][min(j + profit[i], P)] + dp[k][j]) % MOD;
			}
		}

		for (int i = 0; i <= G; ++i)
			res = (res + dp[i][P]) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};