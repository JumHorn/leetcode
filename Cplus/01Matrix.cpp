#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
	{
		if (matrix.empty() || matrix[0].empty())
			return matrix;
		int M = matrix.size(), N = matrix[0].size();
		queue<pair<int, int>> q; //{row,col}
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (matrix[i][j] == 0)
					q.push({i, j});
				else
					matrix[i][j] = INT_MAX;
			}
		}
		while (!q.empty())
		{
			auto pos = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int path[] = {-1, 0, 1, 0, -1};
				int x = pos.first + path[i], y = pos.second + path[i + 1];
				if (x >= 0 && x < M && y >= 0 && y < N)
				{
					int val = matrix[pos.first][pos.second];
					if (matrix[x][y] > val)
					{
						matrix[x][y] = val + 1;
						q.push({x, y});
					}
				}
			}
		}
		return matrix;
	}
};