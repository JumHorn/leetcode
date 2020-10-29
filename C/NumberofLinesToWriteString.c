#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *numberOfLines(int *widths, int widthsSize, char *S, int *returnSize)
{
	int *res = (int *)malloc(sizeof(int) * 2);
	*returnSize = 2;
	int line = 1, len = 0;
	for (; *S; ++S)
	{
		len += widths[*S - 'a'];
		if (len == 100)
		{
			len = 0;
			++line;
		}
		else if (len > 100)
		{
			len = widths[*S - 'a'];
			++line;
		}
	}
	res[0] = line;
	res[1] = len;
	return res;
}