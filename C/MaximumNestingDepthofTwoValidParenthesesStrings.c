#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *maxDepthAfterSplit(char *seq, int *returnSize)
{
	*returnSize = strlen(seq);
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	int index = 0, count = 0;
	while (*seq)
	{
		if (*seq == '(')
		{
			++count;
			res[index++] = (count & 1);
		}
		else
		{
			--count;
			res[index++] = (1 ^ count & 1);
		}
		++seq;
	}
	return res;
}