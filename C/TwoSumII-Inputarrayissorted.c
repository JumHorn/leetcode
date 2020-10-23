#include <stdlib.h>

int *mallocRes(int a, int b, int *returnSize)
{
	*returnSize = 2;
	int *res = (int *)malloc(sizeof(int) * 2);
	res[0] = a;
	res[1] = b;
	return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
	*returnSize = 2;
	int i = 0, j = numbersSize - 1;
	while (i < j)
	{
		if (numbers[i] + numbers[j] == target)
			return mallocRes(i + 1, j + 1, returnSize);
		numbers[i] + numbers[j] < target ? ++i : --j;
	}
	*returnSize = 0;
	return NULL;
}