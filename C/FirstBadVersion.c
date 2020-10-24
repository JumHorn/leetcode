#include <stdbool.h>

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

int firstBadVersion(int n)
{
	int lo = 1, hi = n;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (!isBadVersion(mi))
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}
