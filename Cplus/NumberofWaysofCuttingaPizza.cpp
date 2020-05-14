#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int ways(vector<string> &pizza, int k)
	{
		int m = pizza.size(), n = pizza[0].length();
		vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
		return memdp(pizza, 0, 0, k, dp);
	}

	int memdp(vector<string> &pizza, int m, int n, int k, vector<vector<vector<int>>> &dp)
	{
		if (dp[m][n][k] != -1)
			return dp[m][n][k];
		int row = pizza.size(), col = pizza[0].length();
		if (k == 1)
		{
			for (int i = m; i < row; i++)
			{
				for (int j = n; j < col; j++)
				{
					if (pizza[i][j] == 'A')
						return 1;
				}
			}
			return 0;
		}
		int res = 0, i = m, j = n;
		while (i < row && !rowHasApple(pizza, i, n))
			++i;
		for (; i < row; i++)
			res = (res + memdp(pizza, i + 1, n, k - 1, dp)) % MOD;
		while (j < col && !colHasApple(pizza, m, j))
			++j;
		for (; j < col; j++)
			res = (res + memdp(pizza, m, j + 1, k - 1, dp)) % MOD;
		return dp[m][n][k] = res % MOD;
	}

	bool rowHasApple(vector<string> &pizza, int row, int col)
	{
		for (int j = col; j < (int)pizza[0].length(); j++)
		{
			if (pizza[row][j] == 'A')
				return true;
		}
		return false;
	}

	bool colHasApple(vector<string> &pizza, int row, int col)
	{
		for (int i = row; i < (int)pizza.size(); i++)
		{
			if (pizza[i][col] == 'A')
				return true;
		}
		return false;
	}

private:
	static const int MOD = 1e9 + 7;
};