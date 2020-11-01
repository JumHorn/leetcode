#include <stdio.h>
#include <stdlib.h>

int bitCount(int n)
{
	int res = 0;
	for (; n != 0; n &= n - 1)
		++res;
	return res;
}

char **readBinaryWatch(int num, int *returnSize)
{
	char **res = (char **)malloc(sizeof(char *) * 200);
	*returnSize = 0;
	for (int hour = 0; hour < 12; ++hour)
	{
		for (int minute = 0; minute < 60; ++minute)
		{
			if (bitCount(hour) + bitCount(minute) == num)
			{
				res[*returnSize] = (char *)malloc(sizeof("00:00"));
				sprintf(res[(*returnSize)++], "%d:%02d", hour, minute);
			}
		}
	}
	return res;
}