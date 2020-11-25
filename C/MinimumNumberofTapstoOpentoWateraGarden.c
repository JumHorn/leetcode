#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int minTaps(int n, int *ranges, int rangesSize)
{
	int interval[n + 1];
	memset(interval, 0, sizeof(interval));
	for (int i = 0; i <= n; ++i)
		interval[max(0, i - ranges[i])] = max(interval[max(0, i - ranges[i])], i + ranges[i]);
	int res = 0, maxright = interval[0], maxjump = 0;
	for (int i = 0; max(maxright, interval[i]) < n; ++i)
	{
		if (i > maxjump)
			return -1;
		maxright = max(maxright, interval[i]);
		if (i == maxjump)
		{
			++res;
			maxjump = maxright;
		}
	}
	return res + 1;
}