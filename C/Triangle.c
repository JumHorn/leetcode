#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
	if (triangleSize == 0)
		return 0;
	if (triangleSize == 1)
		return triangle[0][0];
	for (int i = 1; i < triangleSize; ++i)
	{
		triangle[i][0] += triangle[i - 1][0];
		triangle[i][triangleColSize[i] - 1] += triangle[i - 1][triangleColSize[i - 1] - 1];
	}
	for (int i = 2; i < triangleSize; ++i)
	{
		for (int j = 1; j < triangleColSize[i] - 1; ++j)
			triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
	}
	int res = INT_MAX;
	for (int j = 0; j < triangleColSize[triangleSize - 1]; ++j)
		res = min(res, triangle[triangleSize - 1][j]);
	return res;
}
