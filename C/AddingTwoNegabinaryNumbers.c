#include <stdlib.h>
#include <string.h>

#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *addNegabinary(int *arr1, int arr1Size, int *arr2, int arr2Size, int *returnSize)
{
	if (arr1Size < arr2Size)
	{
		int *arr = arr1;
		arr1 = arr2;
		arr2 = arr;
		swap(arr1Size, arr2Size);
	}
	int carry = 0;
	for (int i = 0; i < arr1Size; i++)
	{
		int tmp;
		if (arr2Size - 1 - i >= 0)
			tmp = carry + arr1[arr1Size - 1 - i] + arr2[arr2Size - 1 - i];
		else if (arr1Size - 1 - i >= 0)
			tmp = carry + arr1[arr1Size - 1 - i];
		else
			tmp = carry;

		if (tmp > 1)
		{
			arr1[arr1Size - 1 - i] = tmp - 2;
			int next;
			if (arr2Size - 2 - i >= 0)
				next = arr1[arr1Size - 2 - i] + arr2[arr2Size - 2 - i] + 1;
			else if (arr1Size - 2 - i >= 0)
				next = arr1[arr1Size - 2 - i] + 1;
			else
				next = 1;

			carry = (next > 1 ? 0 : 1);
			if (next > 1)
				next -= 2;
			if (arr1Size - 2 - i >= 0)
				arr1[arr1Size - 2 - i] = next;
			else
				carry = next;
			i++;
		}
		else
		{
			if (arr1Size - 1 - i >= 0)
			{
				arr1[arr1Size - 1 - i] = tmp;
				carry = 0;
			}
			else
				carry = tmp;
		}
	}
	int *res;
	if (carry == 0)
	{
		while (arr1Size > 1 && *arr1 == 0)
		{
			--arr1Size;
			++arr1;
		}
		*returnSize = arr1Size;
		res = (int *)malloc(arr1Size * sizeof(int));
		memcpy(res, arr1, arr1Size * sizeof(int));
		return res;
	}
	*returnSize = arr1Size + 2;
	res = (int *)malloc(*returnSize * sizeof(int));
	memcpy(res + 2, arr1, arr1Size * sizeof(int));
	res[0] = 1;
	res[1] = 1;
	return res;
}

