#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
	{
		if (matrix.empty() || matrix[0].empty())
			return {};
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> dp1(m, vector<int>(n)), dp2(m, vector<int>(n)), res;
		for (int i = 0; i < m; i++)
		{
			dfs(matrix, dp1, i, 0);
			dfs(matrix, dp2, i, n - 1);
		}
		for (int j = 0; j < n; j++)
		{
			dfs(matrix, dp1, 0, j);
			dfs(matrix, dp2, m - 1, j);
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				if (dp1[i][j] == 1 && dp2[i][j] == 1)
					res.push_back({i, j});
		}
		return res;
	}

	void dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j)
	{
		if (dp[i][j] != 0)
			return;
		dp[i][j] = 1;
		int m = matrix.size(), n = matrix[0].size();
		if (i - 1 >= 0 && matrix[i - 1][j] >= matrix[i][j])
			dfs(matrix, dp, i - 1, j);
		if (j - 1 >= 0 && matrix[i][j - 1] >= matrix[i][j])
			dfs(matrix, dp, i, j - 1);
		if (i + 1 < m && matrix[i + 1][j] >= matrix[i][j])
			dfs(matrix, dp, i + 1, j);
		if (j + 1 < n && matrix[i][j + 1] >= matrix[i][j])
			dfs(matrix, dp, i, j + 1);
	}
};