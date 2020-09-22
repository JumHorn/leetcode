#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *diffWaysToCompute(char *input, int *returnSize)
{
	int *res = (int *)malloc(sizeof(int) * 10000);
	*returnSize = 0;
	for (int k = 0; input[k]; ++k)
	{
		if (input[k] == '+' || input[k] == '-' || input[k] == '*')
		{
			int leftsize = 0, rightsize = 0;
			char old = input[k];
			input[k] = '\0';
			int *left = diffWaysToCompute(input, &leftsize);
			int *right = diffWaysToCompute(input + k + 1, &rightsize);
			input[k] = old;
			for (int i = 0; i < leftsize; ++i)
			{
				for (int j = 0; j < rightsize; ++j)
				{
					if (input[k] == '+')
						res[*returnSize] = left[i] + right[j];
					else if (input[k] == '-')
						res[*returnSize] = left[i] - right[j];
					else
						res[*returnSize] = left[i] * right[j];
					++*returnSize;
				}
			}
		}
	}
	if (*returnSize == 0)
	{
		*returnSize = 1;
		res[0] = atoi(input);
	}
	return res;
}