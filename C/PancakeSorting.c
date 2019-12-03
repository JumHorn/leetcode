#include <stdlib.h>

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b)

void reverse(int* A, int start, int end)
{
	while (start < end)
	{
		swap(A[start], A[end]);
		start++;
		end--;
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pancakeSort(int* A, int ASize, int* returnSize)
{
	int* res = (int*)malloc(sizeof(int) * (ASize * 2 - 1));
	*returnSize = 0;
	for (int i = 0; i < ASize - 1; i++)
	{
		int index = 0, min = A[0];
		for (int j = 0; j < ASize - i; j++)
		{
			if (A[j] < min)
			{
				index = j;
				min = A[j];
			}
		}
		if (index != ASize - i - 1)
		{
			res[(*returnSize)++] = index + 1;
			reverse(A, 0, index);
			res[(*returnSize)++] = ASize - i;
			reverse(A, 0, ASize - i - 1);
		}
	}
	res[(*returnSize)++] = ASize;
	return res;
}

