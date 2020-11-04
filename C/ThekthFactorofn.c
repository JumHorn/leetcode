#include <stdbool.h>

int kthFactor(int n, int k)
{
	int factor[100], factorSize = 0;
	for (int i = 1; i * i <= n && factorSize < k; ++i)
	{
		if (n % i == 0)
			factor[factorSize++] = i;
	}
	if (k <= factorSize)
		return factor[factorSize - 1];
	bool square = (factor[factorSize - 1] * factor[factorSize - 1] == n);
	if (k > factorSize * 2 - (square ? 1 : 0))
		return -1;
	return n / factor[factorSize - (k - factorSize)];
}
