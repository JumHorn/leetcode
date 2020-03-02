#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int countSquares(vector<vector<int>> &matrix)
	{
		int m = matrix.size(), n = matrix[0].size();
		int res = 0;
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + matrix[i][j];
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 1; i + k <= m && j + k <= n; k++)
				{
					int ones = dp[i + k][j + k] - dp[i + k][j] - dp[i][j + k] + dp[i][j];
					if (ones != k * k)
						break;
					res++;
				}
			}
		}
		return res;
	}
};