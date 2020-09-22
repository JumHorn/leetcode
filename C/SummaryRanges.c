#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize)
{
	char staticRes[1000][100];
	memset(staticRes, 0, sizeof(staticRes));
	*returnSize = 0;
	if (numsSize == 0)
		return NULL;
	sprintf(staticRes[0], "%d", nums[0]);
	for (int i = 1, j = 0; i < numsSize; ++i)
	{
		if ((long)nums[i] - nums[i - 1] == 1)
			sprintf(staticRes[*returnSize], "%d->%d", nums[j], nums[i]);
		else
		{
			sprintf(staticRes[++*returnSize], "%d", nums[i]);
			j = i;
		}
	}
	++*returnSize;
	char** res = (char**)malloc(sizeof(char*) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (char*)malloc(sizeof(char) * (strlen(staticRes[i]) + 1));
		strcpy(res[i], staticRes[i]);
	}
	return res;
}
