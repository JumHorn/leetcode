#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<int>> res(M, vector<int>(N));
		for (int l = 0; l < min(M, N) / 2; ++l)
		{
			vector<int> layer;
			for (int j = l; j < N - l; ++j)
				layer.push_back(grid[l][j]);
			for (int i = l + 1; i < M - l; ++i)
				layer.push_back(grid[i][N - l - 1]);

			for (int j = N - 2 - l; j >= l; --j)
				layer.push_back(grid[M - l - 1][j]);
			for (int i = M - l - 2; i > l; --i)
				layer.push_back(grid[i][l]);

			int index = 0, size = layer.size();
			for (int j = l; j < N - l; ++j)
			{
				res[l][j] = layer[(index + k) % size];
				++index;
			}
			for (int i = l + 1; i < M - l; ++i)
			{
				res[i][N - l - 1] = layer[(index + k) % size];
				++index;
			}

			for (int j = N - 2 - l; j >= l; --j)
			{
				res[M - l - 1][j] = layer[(index + k) % size];
				++index;
			}
			for (int i = M - l - 2; i > l; --i)
			{
				res[i][l] = layer[(index + k) % size];
				++index;
			}
		}
		return res;
	}
};