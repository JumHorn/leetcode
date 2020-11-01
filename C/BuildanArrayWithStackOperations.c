#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize)
{
	char** res = (char**)malloc(sizeof(char*) * (n * 2));
	*returnSize = 0;
	int last = target[targetSize - 1];
	for (int i = 1, j = 0; i <= last; ++i)
	{
		if (i == target[j])
		{
			++j;
			res[(*returnSize)++] = strdup("Push");
		}
		else
		{
			res[(*returnSize)++] = strdup("Push");
			res[(*returnSize)++] = strdup("Pop");
		}
	}
	return res;
}
