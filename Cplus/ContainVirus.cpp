#include <algorithm>
#include <vector>
using namespace std;

/*
a year later I still fail to pass the testcase below
however My code is much clear than before.
Even I can print the result to prove my understandings
*/

class Solution
{
public:
	int containVirus(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size(), res = 0;
		vector<vector<vector<int>>> wall(M, vector<vector<int>>(N, vector<int>(2)));

		while (true)
		{
			int x, y, virus = 0, color = 2;
			for (int i = 0; i < M; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					if (grid[i][j] == 1)
					{
						int expand = colorGrid(grid, wall, i, j, color++);
						if (expand > virus)
						{
							virus = expand;
							x = i;
							y = j;
						}
					}
				}
			}
			if (virus == 0)
				break;
			buildWall(grid, wall, x, y, color);
			clearVirus(grid, x, y);
			vector<vector<int>> nextgrid(M, vector<int>(N));
			for (int i = 0; i < M; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					if (grid[i][j] != 0)
						expandVirus(grid, nextgrid, wall, i, j);
				}
			}
			grid = nextgrid;
		}
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				res += wall[i][j][0] + wall[i][j][1];
		}
		return res;
	}

	void expandVirus(vector<vector<int>> &grid, vector<vector<int>> &nextgrid, vector<vector<vector<int>>> &wall, int row, int col)
	{
		int M = grid.size(), N = grid[0].size();
		nextgrid[row][col] = 1;
		if (grid[row][col] == 0)
			return;
		grid[row][col] = 0;
		if (row - 1 >= 0 && wall[row - 1][col][1] != 1)
			expandVirus(grid, nextgrid, wall, row - 1, col);
		if (row + 1 < M && wall[row][col][1] != 1)
			expandVirus(grid, nextgrid, wall, row + 1, col);
		if (col - 1 >= 0 && wall[row][col - 1][0] != 1)
			expandVirus(grid, nextgrid, wall, row, col - 1);
		if (col + 1 < N && wall[row][col][0] != 1)
			expandVirus(grid, nextgrid, wall, row, col + 1);
	}

	void clearVirus(vector<vector<int>> &grid, int row, int col)
	{
		int M = grid.size(), N = grid[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N)
			return;
		if (grid[row][col] == 0)
			return;
		grid[row][col] = 0;
		clearVirus(grid, row - 1, col);
		clearVirus(grid, row + 1, col);
		clearVirus(grid, row, col - 1);
		clearVirus(grid, row, col + 1);
	}

	void buildWall(vector<vector<int>> &grid, vector<vector<vector<int>>> &wall, int row, int col, int color)
	{
		int M = grid.size(), N = grid[0].size();
		if (grid[row][col] == 0 || grid[row][col] == color)
			return;
		grid[row][col] = color;
		if (row - 1 >= 0)
		{
			if (grid[row - 1][col] == 0)
				wall[row - 1][col][1] = 1;
			else
				buildWall(grid, wall, row - 1, col, color);
		}
		if (row + 1 < M)
		{
			if (grid[row + 1][col] == 0)
				wall[row][col][1] = 1;
			else
				buildWall(grid, wall, row + 1, col, color);
		}
		if (col - 1 >= 0)
		{
			if (grid[row][col - 1] == 0)
				wall[row][col - 1][0] = 1;
			else
				buildWall(grid, wall, row, col - 1, color);
		}
		if (col + 1 < N)
		{
			if (grid[row][col + 1] == 0)
				wall[row][col][0] = 1;
			else
				buildWall(grid, wall, row, col + 1, color);
		}
	}

	//color the connected component with color,return sum of node which can be affected(no wall between them)
	int colorGrid(vector<vector<int>> &grid, vector<vector<vector<int>>> &wall, int row, int col, int color)
	{
		int M = grid.size(), N = grid[0].size();
		if (grid[row][col] == color)
			return 0;
		if (grid[row][col] == 0)
			return 1;
		int res = 0;
		grid[row][col] = color;
		if (row - 1 >= 0 && wall[row - 1][col][1] != 1)
			res += colorGrid(grid, wall, row - 1, col, color);
		if (row + 1 < M && wall[row][col][1] != 1)
			res += colorGrid(grid, wall, row + 1, col, color);
		if (col - 1 >= 0 && wall[row][col - 1][0] != 1)
			res += colorGrid(grid, wall, row, col - 1, color);
		if (col + 1 < N && wall[row][col][0] != 1)
			res += colorGrid(grid, wall, row, col + 1, color);
		return res;
	}
};

int main()
{
	//Output 40
	//Expected 38
	vector<vector<int>> grid =
		{
			{0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
			{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
			{0, 0, 1, 1, 1, 0, 0, 0, 1, 0},
			{0, 0, 0, 1, 1, 0, 0, 1, 1, 0},
			{0, 1, 0, 0, 1, 0, 1, 1, 0, 1},
			{0, 0, 0, 1, 0, 1, 0, 1, 1, 1},
			{0, 1, 0, 0, 1, 0, 0, 1, 1, 0},
			{0, 1, 0, 1, 0, 0, 0, 1, 1, 0},
			{0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
			{1, 0, 1, 1, 0, 1, 0, 1, 0, 1}};
	Solution sol;
	sol.containVirus(grid);
	return 0;
}