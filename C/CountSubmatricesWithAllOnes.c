#include <string.h>

int numSubmat(int **mat, int matSize, int *matColSize)
{
	int M = matSize, N = *matColSize, res = 0;
	int height[N];
	memset(height, 0, sizeof(height));
	for (int i = 0; i < M; ++i)
	{
		int stack[N][2], top = -1; //{index,count of submat} increasing stack
		for (int j = 0; j < N; ++j)
		{
			height[j] = mat[i][j] == 0 ? 0 : (height[j] + 1); //  height of histogram;
			int sum = 0;
			while (top != -1 && height[stack[top][0]] >= height[j])
				--top;
			if (top == -1)
				sum = height[j] * (j + 1);
			else
				sum = height[j] * (j - stack[top][0]) + stack[top][1];
			++top;
			stack[top][0] = j;
			stack[top][1] = sum;
			res += sum;
		}
	}
	return res;
}