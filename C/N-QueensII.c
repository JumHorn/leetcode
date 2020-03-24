#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

bool queenCheck(int n, int (*queen)[n], int i, int j)
{
	int drc[][2] = {{-1, 0}, {-1, -1}, {-1, 1}};
	for (int l = 1; l < n; l++)
	{
		for (int m = 0; m < ARRAY_SIZE(drc); m++)
		{
			int x = i + drc[m][0] * l, y = j + drc[m][1] * l;
			if (x < 0 || x >= n || y < 0 || y >= n)
				continue;
			if (queen[x][y] == 1)
				return false;
		}
	}
	return true;
}

int dfs(int n, int (*queen)[n], int i)
{
	if (i >= n)
		return 1;
	int res = 0;
	for (int j = 0; j < n; j++)
	{
		queen[i][j] = 1;
		if (queenCheck(n, queen, i, j))
			res += dfs(n, queen, i + 1);
		queen[i][j] = 0;
	}
	return res;
}

int totalNQueens(int n)
{
	if (n <= 0)
		return 0;
	int queen[n][n];
	memset(queen, 0, sizeof(queen));
	return dfs(n, queen, 0);
}