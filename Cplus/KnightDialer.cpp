#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int knightDialer(int N)
	{
		vector<vector<int>> graph = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
		vector<int> dp(10, 1);
		for (int i = 1; i < N; i++)
		{
			vector<int> tmp(10, 0);
			for (int j = 0; j < 10; j++)
			{
				for (int k = 0; k < (int)graph[j].size(); k++)
					tmp[graph[j][k]] = (tmp[graph[j][k]] + dp[j]) % MOD;
			}
			dp = tmp;
		}
		int res = 0;
		for (int i = 0; i < 10; i++)
			res = (res + dp[i]) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};
