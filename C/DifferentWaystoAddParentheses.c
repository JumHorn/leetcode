#include <stdlib.h>
#include <string.h>

typedef struct vector
{
	int data[2000];
	int size;
} vector;

vector compute(char *input)
{
	vector res = {.size = 0};
	for (int k = 0; input[k]; ++k)
	{
		if (input[k] == '+' || input[k] == '-' || input[k] == '*')
		{
			char old = input[k];
			input[k] = '\0';
			vector left = compute(input);
			vector right = compute(input + k + 1);
			input[k] = old;
			for (int i = 0; i < left.size; ++i)
			{
				for (int j = 0; j < right.size; ++j)
				{
					if (input[k] == '+')
						res.data[res.size] = left.data[i] + right.data[j];
					else if (input[k] == '-')
						res.data[res.size] = left.data[i] - right.data[j];
					else
						res.data[res.size] = left.data[i] * right.data[j];
					++res.size;
				}
			}
		}
	}
	if (res.size == 0)
	{
		res.size = 1;
		res.data[0] = atoi(input);
	}
	return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *diffWaysToCompute(char *input, int *returnSize)
{
	vector val = compute(input);
	*returnSize = val.size;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(res, val.data, sizeof(int) * (*returnSize));
	return res;
}