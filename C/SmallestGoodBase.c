#include <math.h>
#include <stdlib.h>

char *smallestGoodBase(char *n)
{
	unsigned long long S = atol(n);
	int max_m = log2(S);
	for (int m = max_m; m >= 2; --m)
	{
		int k = pow(S, 1.0 / m);
		unsigned long long sum = 1, prod = 1;
		for (int i = 0; i < m; ++i)
			sum += (prod *= k);
		if (sum == S)
		{
			sprintf(n, "%d", k);
			return n;
		}
	}
	sprintf(n, "%ld", S - 1);
	return n;
}