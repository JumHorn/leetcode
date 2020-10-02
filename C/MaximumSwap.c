#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))

int maximumSwap(int num)
{
	char val[10];
	sprintf(val, "%d", num);
	for (int i = 0, k = 0; val[i]; ++i)
	{
		if (k <= i)
		{
			k = i;
			for (int j = i + 1; val[j]; ++j)
			{
				if (val[k] <= val[j])
					k = j;
			}
		}
		if (k != i && val[k] > val[i])
		{
			swap(val[i], val[k]);
			break;
		}
	}
	return atoi(val);
}
