#include <string.h>

void dfs(int** M, int MSize, int color, int students, int* group)
{
	if (group[students] != 0)
		return;
	group[students] = color;
	for (int i = 0; i < MSize; ++i)
	{
		if (M[students][i] == 1)
			dfs(M, MSize, color, i, group);
	}
}

int findCircleNum(int** M, int MSize, int* MColSize)
{
	int res = 0;
	int group[MSize];
	memset(group, 0, sizeof(group));
	for (int i = 0; i < MSize; ++i)
	{
		if (group[i] == 0)
			dfs(M, MSize, ++res, i, group);
	}
	return res;
}
