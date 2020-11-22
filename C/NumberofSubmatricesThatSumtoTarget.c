#include <limits.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//divide and conquer
void merge(int *arr, int *dup, int first, int mid, int last)
{
	for (int i = first, j = mid, d = 0; i < mid || j < last;)
	{
		if (i == mid)
			dup[d++] = arr[j++];
		else if (j == last)
			dup[d++] = arr[i++];
		else
			dup[d++] = (arr[i] > arr[j]) ? arr[j++] : arr[i++];
	}
	memcpy(arr + first, dup, sizeof(int) * (last - first));
}

int divide(int *arr, int *dup, int first, int last, int target)
{
	if (last - first < 2)
		return 0;
	int mid = (last - first) / 2 + first, res = 0;
	res += divide(arr, dup, first, mid, target);
	res += divide(arr, dup, mid, last, target);
	for (int i = first, j = mid, k = j; i < mid && j < last; ++i)
	{
		while (j < last && arr[j] - arr[i] < target)
			++j;
		while (k < last && arr[k] - arr[i] <= target)
			++k;
		if (j < last && arr[j] - arr[i] == target)
			res += k - j;
	}
	merge(arr, dup, first, mid, last);
	return res;
}
/********end of divide and conquer********/

int numSubmatrixSumTarget(int **matrix, int matrixSize, int *matrixColSize, int target)
{
	int M = matrixSize, N = *matrixColSize, res = 0;
	int arr[M + 1], dup[M + 1], sum[M + 1];
	for (int col = 0; col < N; ++col)
	{
		memset(sum, 0, sizeof(sum));
		for (int j = col; j < N; ++j)
		{
			for (int i = 0; i < M; ++i)
				sum[i + 1] += matrix[i][j];
			memcpy(arr, sum, sizeof(arr));
			for (int i = 1; i <= M; ++i)
				arr[i] += arr[i - 1];
			res += divide(arr, dup, 0, M + 1, target);
		}
	}
	return res;
}