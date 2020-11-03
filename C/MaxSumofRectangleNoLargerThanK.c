#include <limits.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

void merge(int *arr, int *dump, int first, int middle, int last)
{
	int i = first, j = middle, d = 0;
	while (i < middle && j < last)
		dump[d++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	while (i < middle)
		dump[d++] = arr[i++];
	while (j < last)
		dump[d++] = arr[j++];
	memcpy(arr + first, dump, d * sizeof(int));
}

int divide(int *arr, int *dump, int first, int last, int k)
{
	if (last - first < 2)
		return INT_MIN;
	int mi = (last - first) / 2 + first;
	int left = divide(arr, dump, first, mi, k);
	int right = divide(arr, dump, mi, last, k);
	int low = max(left, right);
	for (int i = first, j = mi; i < mi && j < last; ++i)
	{
		while (j < last && arr[j] - arr[i] <= k)
		{
			low = max(low, arr[j] - arr[i]);
			j++;
		}
	}
	merge(arr, dump, first, mi, last);
	return low;
}

int maxSumSubmatrix(int **matrix, int matrixSize, int *matrixColSize, int k)
{
	int m = matrixSize, n = *matrixColSize, res = INT_MIN;
	int arr[m + 1], dump[m + 1], sum[m + 1];
	for (int col = 0; col < n; col++)
	{
		memset(sum, 0, sizeof(sum));
		for (int j = col; j < n; j++)
		{
			for (int i = 0; i < m; ++i)
				sum[i + 1] += matrix[i][j];
			memcpy(arr, sum, sizeof(arr));
			for (int i = 1; i <= m; ++i)
				arr[i] += arr[i - 1];
			int tmp = divide(arr, dump, 0, m + 1, k);
			res = max(res, tmp);
		}
	}
	return res;
}