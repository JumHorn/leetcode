#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
	{
		if (matrix.empty() || matrix[0].empty())
			return {};
		int M = matrix.size(), N = matrix[0].size();
		vector<vector<int>> color1(M, vector<int>(N)), color2(M, vector<int>(N)), res;
		for (int i = 0; i < M; ++i)
		{
			dfs(matrix, color1, i, 0);
			dfs(matrix, color2, i, N - 1);
		}
		for (int j = 0; j < N; ++j)
		{
			dfs(matrix, color1, 0, j);
			dfs(matrix, color2, M - 1, j);
		}
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (color1[i][j] == 1 && color2[i][j] == 1)
					res.push_back({i, j});
			}
		}
		return res;
	}

	void dfs(vector<vector<int>> &matrix, vector<vector<int>> &color, int row, int col)
	{
		int M = matrix.size(), N = matrix[0].size();
		int path[] = {-1, 0, 1, 0, -1};
		if (color[row][col] != 0)
			return;
		color[row][col] = 1;
		for (int k = 0; k < 4; ++k)
		{
			int x = row + path[k], y = col + path[k + 1];
			if (x >= 0 && x < M && y >= 0 && y < N && matrix[x][y] >= matrix[row][col])
				dfs(matrix, color, x, y);
		}
	}
};