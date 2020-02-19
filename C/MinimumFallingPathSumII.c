#include <limits.h>

int minFallingPathSum(int** arr, int arrSize, int* arrColSize)
{
	int m = arrSize, n = *arrColSize;
	for (int i = 1; i < m; i++)
	{
		int first = INT_MAX, second = INT_MAX, index = -1;
		for (int j = 0; j < n; j++)
		{
			if (arr[i - 1][j] < first)
			{
				second = first;
				first = arr[i - 1][j];
				index = j;
			}
			else if (arr[i - 1][j] < second)
				second = arr[i - 1][j];
		}
		for (int j = 0; j < n; j++)
		{
			if (index == j)
				arr[i][j] += second;
			else
				arr[i][j] += first;
		}
	}
	int res = INT_MAX;
	for (int j = 0; j < n; j++)
		if (arr[m - 1][j] < res)
			res = arr[m - 1][j];
	return res;
}

