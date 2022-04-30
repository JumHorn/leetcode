#include <vector>
using namespace std;

class Solution
{
public:
	int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
	{
		vector<vector<int>> grid(m, vector<int>(n));
		for (auto &g : guards)
			grid[g[0]][g[1]] = 1;
		for (auto &w : walls)
			grid[w[0]][w[1]] = 2;

		//left
		for (int i = 0; i < m; ++i)
		{
			int guard = 0;
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j] == 0)
					grid[i][j] = guard;
				else if (grid[i][j] == 1)
					guard = 3;
				else if (grid[i][j] == 2)
					guard = 0;
			}
		}
		//right
		for (int i = 0; i < m; ++i)
		{
			int guard = 0;
			for (int j = n - 1; j >= 0; --j)
			{
				if (grid[i][j] == 0)
					grid[i][j] = guard;
				else if (grid[i][j] == 1)
					guard = 3;
				else if (grid[i][j] == 2)
					guard = 0;
			}
		}

		//down
		for (int j = 0; j < n; ++j)
		{
			int guard = 0;
			for (int i = 0; i < m; ++i)
			{
				if (grid[i][j] == 0)
					grid[i][j] = guard;
				else if (grid[i][j] == 1)
					guard = 3;
				else if (grid[i][j] == 2)
					guard = 0;
			}
		}

		//up
		for (int j = 0; j < n; ++j)
		{
			int guard = 0;
			for (int i = m - 1; i >= 0; --i)
			{
				if (grid[i][j] == 0)
					grid[i][j] = guard;
				else if (grid[i][j] == 1)
					guard = 3;
				else if (grid[i][j] == 2)
					guard = 0;
			}
		}

		int res = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j] == 0)
					++res;
			}
		}
		return res;
	}
};