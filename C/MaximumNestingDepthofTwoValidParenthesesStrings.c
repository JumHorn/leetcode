#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char* seq, int* returnSize)
{
	*returnSize = strlen(seq);
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	int index = 0, s = 0;
	while (*seq)
	{
		if (*seq == '(')
		{
			s++;
			res[index++] = (s & 1);
		}
		else
		{
			s--;
			res[index++] = 1 - (s & 1);
		}
		seq++;
	}
	return res;
}

