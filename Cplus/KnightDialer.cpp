#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int knightDialer(int n)
	{
		vector<vector<int>> graph = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
		vector<int> dp(10, 1);
		for (int i = 1; i < n; ++i)
		{
			vector<int> nextdp(10);
			for (int j = 0; j < 10; ++j)
			{
				for (int k = 0; k < (int)graph[j].size(); k++)
					nextdp[graph[j][k]] = (nextdp[graph[j][k]] + dp[j]) % MOD;
			}
			dp = nextdp;
		}
		int res = 0;
		for (auto n : dp)
			res = (res + n) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};