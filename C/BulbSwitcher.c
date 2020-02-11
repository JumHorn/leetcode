#include <stdlib.h>
#include <string.h>

int bulbSwitch(int n)
{
	if (n == 1)
		return n;
	int *bulb = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		bulb[i] = 1;
	for (int i = 1; i < n; i++)
	{
		int j = i;
		while (j < n)
		{
			bulb[j] = !bulb[j];
			j += i + 1;
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		if (bulb[i] != 0)
			res++;
	return res;
}

