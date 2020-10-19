#include <stdlib.h>
#include <string.h>

#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

void reverse(int *arr, int first, int last)
{
	while (first < last)
	{
		swap(arr[first], arr[last]);
		++first;
		--last;
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *addNegabinary(int *arr1, int arr1Size, int *arr2, int arr2Size, int *returnSize)
{
	int *res = (int *)malloc(sizeof(int) * (max(arr1Size, arr2Size) + 2));
	*returnSize = 0;
	int carry = 0, i = arr1Size - 1, j = arr2Size - 1;
	while (i >= 0 || j >= 0 || carry)
	{
		if (i >= 0)
			carry += arr1[i--];
		if (j >= 0)
			carry += arr2[j--];
		res[(*returnSize)++] = (carry & 1);
		carry = -(carry >> 1);
	}
	while (*returnSize > 1 && res[*returnSize - 1] == 0)
		--*returnSize;
	reverse(res, 0, *returnSize - 1);
	return res;
}