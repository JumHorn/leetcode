#include <stdlib.h>

void reverse(int *arr, int first, int last)
{
	for (; first < last; ++first, --last)
	{
		int tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *addToArrayForm(int *A, int ASize, int K, int *returnSize)
{
	int *res = (int *)malloc(sizeof(int) * (ASize + 20));
	*returnSize = 0;
	for (int carry = 0, i = ASize - 1; K != 0 || carry != 0 || i >= 0; --i, K /= 10)
	{
		if (i >= 0)
			carry += A[i];
		carry += K % 10;
		res[(*returnSize)++] = carry % 10;
		carry /= 10;
	}
	reverse(res, 0, *returnSize - 1);
	return res;
}