#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize)
{
	*returnSize = barcodesSize;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	int hash[10001] = {0};
	int mostvalue = 0;
	for (int i = 0; i < barcodesSize; ++i)
	{
		if (++hash[barcodes[i]] > hash[mostvalue])
			mostvalue = barcodes[i];
	}
	int i = 0;
	for (; --hash[mostvalue] >= 0; i += 2)
		res[i] = mostvalue;
	for (int n = 0; n <= 10000; ++n)
	{
		if (hash[n] <= 0)
			continue;
		while (--hash[n] >= 0)
		{
			if (i >= barcodesSize)
				i = 1;
			res[i] = n;
			i += 2;
		}
	}
	return res;
}
