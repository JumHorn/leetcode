#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<int>> res(M, vector<int>(N, 0));
		k %= M * N;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int index = (i * N + j + k) % (M * N);
				int x = index / N, y = index % N;
				res[x][y] = grid[i][j];
			}
		}
		return res;
	}
};