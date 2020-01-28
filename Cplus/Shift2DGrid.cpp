#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
	{
		for (int i = 0; i < k; i++)
			shift(grid);
		return grid;
	}

	void shift(vector<vector<int>>& grid)
	{
		vector<int> v(grid.size());
		for (int i = 0; i < (int)grid.size() - 1; i++)
			v[i + 1] = grid[i].back();
		v[0] = grid.back().back();
		for (int i = grid[0].size() - 1; i > 0; i--)
			for (int j = grid.size() - 1; j >= 0; j--)
				grid[j][i] = grid[j][i - 1];
		for (int i = 0; i < (int)grid.size(); i++)
			grid[i][0] = v[i];
	}
};
