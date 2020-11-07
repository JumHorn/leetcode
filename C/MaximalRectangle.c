#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int largestRectangleInHistogram(int* heights, int heightsSize)
{
	int stack[heightsSize + 1], top = 0, res = 0;
	stack[0] = -1;
	for (int i = 0; i < heightsSize; ++i)
	{
		for (; top != 0 && heights[i] <= heights[stack[top]]; --top)
			res = max(res, heights[stack[top]] * (i - stack[top - 1] - 1));
		stack[++top] = i;
	}

	for (int right = stack[top] + 1; top != 0; --top)
		res = max(res, heights[stack[top]] * (right - stack[top - 1] - 1));
	return res;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize)
{
	if (matrixSize == 0 || *matrixColSize == 0)
		return 0;
	int M = matrixSize, N = *matrixColSize, histogram[N], res = 0;
	memset(histogram, 0, sizeof(histogram));
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			matrix[i][j] == '1' ? ++histogram[j] : (histogram[j] = 0);
		int area = largestRectangleInHistogram(histogram, N);
		res = max(res, area);
	}
	return res;
}
