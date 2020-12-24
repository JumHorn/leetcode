#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int leastBricks(int **wall, int wallSize, int *wallColSize)
{
	int dp[20001] = {0};
	int res = wallSize;
	for (int i = 0; i < wallSize; ++i)
	{
		int prefixsum = 0;
		for (int j = 0; j < wallColSize[i] - 1; ++j) // skip last brick
		{
			prefixsum += wall[i][j];
			++dp[prefixsum];
			res = min(res, wallSize - dp[prefixsum]);
		}
	}
	return res;
}