
#define swap(a, b) ((a) != (b) && ((a) ^= (b) ^= (a) ^= (b)))

int minSwaps(int** grid, int gridSize, int* gridColSize)
{
	int v[gridSize];
	for (int i = 0; i < gridSize; ++i)
	{
		int j = gridSize - 1;
		while (j >= 0 && grid[i][j] == 0)
			--j;
		v[i] = gridSize - 1 - j;
	}

	int res = 0;
	for (int i = 0, j = 0; i < gridSize; ++i)
	{
		if (v[i] >= gridSize - 1 - i)
			continue;
		for (j = i + 1; j < gridSize && v[j] < gridSize - 1 - i;)
			++j;
		if (j == gridSize)
			return -1;
		res += j - i;
		for (; j > i; --j)
			swap(v[j], v[j - 1]);
	}
	return res;
}
