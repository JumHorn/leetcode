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

int divide(int *arr, int *dup, int first, int last, int k)
{
	if (last - first < 2)
		return INT_MIN;
	int mid = (last - first) / 2 + first;
	int left = divide(arr, dup, first, mid, k);
	int right = divide(arr, dup, mid, last, k);
	int res = max(left, right);
	for (int i = first, j = mid; i < mid && j < last; ++i)
	{
		for (; j < last && arr[j] - arr[i] <= k; ++j)
			res = max(res, arr[j] - arr[i]);
	}
	merge(arr, dup, first, mid, last);
	return res;
}
/********end of divide and conquer********/

int maxSumSubmatrix(int **matrix, int matrixSize, int *matrixColSize, int k)
{
	int M = matrixSize, N = *matrixColSize, res = INT_MIN;
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
			int maxSumOfRect = divide(arr, dup, 0, M + 1, k);
			res = max(res, maxSumOfRect);
		}
	}
	return res;
}