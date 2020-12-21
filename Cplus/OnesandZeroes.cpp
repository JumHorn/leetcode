#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//knapsack

class Solution
{
public:
	int findMaxForm(vector<string> &strs, int m, int n)
	{
		if (strs.empty())
			return 0;
		int N = strs.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		vector<vector<int>> binstr(N, vector<int>(2));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < (int)strs[i].size(); ++j)
				++binstr[i][strs[i][j] - '0'];
		}
		for (int k = 0; k < N; ++k)
		{
			for (int i = m; i >= 0; --i)
			{
				for (int j = n; j >= 0; --j)
				{
					if (i >= binstr[k][0] && j >= binstr[k][1])
						dp[i][j] = max(dp[i][j], 1 + dp[i - binstr[k][0]][j - binstr[k][1]]);
				}
			}
		}
		return dp[m][n];
	}
};