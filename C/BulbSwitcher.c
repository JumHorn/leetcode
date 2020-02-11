#include <stdlib.h>
#include <string.h>

int bulbSwitch(int n)
{
	if (n == 1)
		return 1;
	long lo = 1, hi = n, mi;
	while (lo < hi)
	{
		mi = (hi - lo) / 2 + lo;
		if (mi * mi <= n)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo - 1;
}
