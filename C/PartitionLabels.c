#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char* S, int* returnSize)
{
	*returnSize = 0;
	int* res = (int*)malloc(sizeof(int) * 500);
	int lastpos[26] = {0};
	for (int i = 0; S[i]; ++i)
		lastpos[S[i] - 'a'] = i;
	for (int i = 0, j = 0; S[i]; ++i)
	{
		j = max(j, lastpos[S[i] - 'a']);
		if (i == j)
			res[(*returnSize)++] = i + 1;
	}
	for (int i = *returnSize - 1; i > 0; --i)
		res[i] -= res[i - 1];
	return res;
}
