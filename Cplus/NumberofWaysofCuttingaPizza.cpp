#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int ways(vector<string> &pizza, int k)
	{
		int M = pizza.size(), N = pizza[0].length();
		vector<vector<vector<int>>> dp(M + 1, vector<vector<int>>(N + 1, vector<int>(k + 1, -1)));
		vector<vector<int>> count(M + 1, vector<int>(N + 1));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				count[i + 1][j + 1] = (count[i][j + 1] + count[i + 1][j] - count[i][j] + (pizza[i][j] == 'A' ? 1 : 0));
		}
		return memdp(count, 0, 0, k, dp);
	}

	int memdp(vector<vector<int>> &count, int r, int c, int k, vector<vector<vector<int>>> &dp)
	{
		if (dp[r][c][k] != -1)
			return dp[r][c][k];
		int row = (int)count.size() - 1, col = (int)count[0].size() - 1;
		if (k == 1)
			return existApple(count, r, c, row, col) ? 1 : 0;
		int res = 0, i = r, j = c;
		while (i < row && !existApple(count, i, c, i + 1, col))
			++i;
		for (; i < row; ++i)
			res = (res + memdp(count, i + 1, c, k - 1, dp)) % MOD;
		while (j < col && !existApple(count, r, j, row, j + 1))
			++j;
		for (; j < col; ++j)
			res = (res + memdp(count, r, j + 1, k - 1, dp)) % MOD;
		return dp[r][c][k] = res;
	}

	bool existApple(vector<vector<int>> &count, int row0, int col0, int row1, int col1)
	{
		return count[row1][col1] - count[row0][col1] - count[row1][col0] + count[row0][col0] > 0;
	}

private:
	static const int MOD = 1e9 + 7;
};