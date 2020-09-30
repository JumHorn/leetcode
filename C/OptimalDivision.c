#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* optimalDivision(int* nums, int numsSize)
{
	char* res = (char*)malloc(sizeof(char) * (numsSize * 4 + 3));
	if (numsSize == 1)
		sprintf(res, "%d", nums[0]);
	else if (numsSize == 2)
		sprintf(res, "%d/%d", nums[0], nums[1]);
	else
	{
		sprintf(res, "%d/(", nums[0]);
		char* p = res;
		for (int i = 1; i < numsSize; ++i)
		{
			while (*p)
				++p;
			if (i == numsSize - 1)
				sprintf(p, "%d)", nums[i]);
			else
				sprintf(p, "%d/", nums[i]);
		}
	}
	return res;
}
