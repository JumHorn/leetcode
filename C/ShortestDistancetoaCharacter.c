#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char* S, char C, int* returnSize)
{
	*returnSize = strlen(S);
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	int pre = -1, cur = -1;
	for (int i = 0, j = 0; i < *returnSize; ++i)
	{
		if (i > cur)
		{
			pre = cur;
			while (j < *returnSize && S[j] != C)
				++j;
			cur = j++;
		}
		int d = *returnSize;
		if (pre >= 0)
			d = min(d, i - pre);
		if (cur < *returnSize)
			d = min(d, cur - i);
		res[i] = d;
	}
	return res;
}
