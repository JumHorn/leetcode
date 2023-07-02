#include <stdbool.h>
#include <string.h>

int countPrimes(int n)
{
	bool prime[n + 1];
	memset(prime, 0, sizeof(prime));
	int res = 0;
	for (int i = 2; i < n; ++i)
	{
		if (!prime[i])
		{
			++res;
			for (int j = i + i; j <= n; j += i)
				prime[j] = true;
		}
	}
	return res;
}
