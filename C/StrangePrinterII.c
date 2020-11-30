#include <stdbool.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

//if true then clear the color
bool checkAndColor(int **grid, int left, int bottom, int right, int top, int color)
{
	for (int i = left; i <= right; ++i)
	{
		for (int j = bottom; j <= top; ++j)
		{
			if (grid[i][j] != -1 && grid[i][j] != color)
				return false;
		}
	}
	for (int i = left; i <= right; ++i)
	{
		for (int j = bottom; j <= top; ++j)
		{
			if (grid[i][j] == color)
				grid[i][j] = -1;
		}
	}
	return true;
}

bool isPrintable(int **targetGrid, int targetGridSize, int *targetGridColSize)
{
	int M = targetGridSize, N = *targetGridColSize;
	int rect[61][4];
	for (int i = 0; i < 61; ++i)
	{
		rect[i][0] = M;
		rect[i][1] = N;
		rect[i][2] = -1;
		rect[i][3] = -1;
	}

	int color[61], colorSize = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int c = targetGrid[i][j];
			if (rect[c][3] == -1)
				color[colorSize++] = c;
			rect[c][0] = min(rect[c][0], i);
			rect[c][1] = min(rect[c][1], j);
			rect[c][2] = max(rect[c][2], i);
			rect[c][3] = max(rect[c][3], j);
		}
	}
	while (colorSize != 0)
	{
		int next_color[61], size = 0;
		for (int i = 0; i < colorSize; ++i)
		{
			int c = color[i];
			if (!checkAndColor(targetGrid, rect[c][0], rect[c][1], rect[c][2], rect[c][3], c))
				next_color[size++] = c;
		}
		if (size == colorSize)
			return false;
		memcpy(color, next_color, sizeof(int) * size);
		colorSize = size;
	}
	return true;
}