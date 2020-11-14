
#define max(a, b) (((a) > (b)) ? (a) : (b))

int colorNode(int **grid, int M, int N, int row, int col, int color)
{
	if (row < 0 || row >= M || col < 0 || col >= N || grid[row][col] != 1)
		return 0;
	int res = 1;
	grid[row][col] = color;
	res += colorNode(grid, M, N, row - 1, col, color);
	res += colorNode(grid, M, N, row + 1, col, color);
	res += colorNode(grid, M, N, row, col - 1, color);
	res += colorNode(grid, M, N, row, col + 1, color);
	return res;
}

int largestIsland(int **grid, int gridSize, int *gridColSize)
{
	int color = 2, colorArr[2000], res = 0;
	//color the grid
	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < *gridColSize; ++j)
		{
			if (grid[i][j] == 1)
			{
				colorArr[color] = colorNode(grid, gridSize, *gridColSize, i, j, color);
				res = max(res, colorArr[color]);
				++color;
			}
		}
	}

	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < *gridColSize; ++j)
		{
			if (grid[i][j] != 0)
				continue;
			int colorset[4], n = 0, area = 0;
			//board dfs direction
			int path[5] = {-1, 0, 1, 0, -1};
			for (int k = 0; k < 4; ++k)
			{
				int dx = i + path[k], dy = j + path[k + 1];
				if (dx < 0 || dx >= gridSize || dy < 0 || dy >= *gridColSize || grid[dx][dy] <= 1)
					continue;
				int c = grid[dx][dy], l = 0;
				while (l < n && colorset[l] != c)
					++l;
				if (l == n) //this color not count yet
				{
					area += colorArr[c];
					colorset[n++] = c;
				}
			}
			res = max(res, area + 1); //1 for self
		}
	}
	return res;
}
