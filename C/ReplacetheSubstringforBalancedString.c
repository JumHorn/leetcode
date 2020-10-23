#include <stdbool.h>

/*
Q 1
R 2
E 3
W 0
*/
#define HASH(x) (((x) % 7) - 3)

bool lowerThanAvg(int *count, int avg)
{
	for (int i = 0; i < 4; ++i)
	{
		if (count[i] > avg)
			return false;
	}
	return true;
}

bool checkBalance(char *s, int *count, int avg, int len)
{
	for (int i = 0; i < len; ++i)
		--count[HASH(s[i])];
	if (lowerThanAvg(count, avg))
		return true;
	for (int i = len; s[i]; ++i)
	{
		--count[HASH(s[i])];
		++count[HASH(s[i - len])];
		if (lowerThanAvg(count, avg))
			return true;
	}
	return false;
}

int balancedString(char *s)
{
	int map[4] = {0}, len = 0;
	for (; s[len]; ++len)
		++map[HASH(s[len])];
	int avg = len / 4, lo = 0, hi = avg * 3;
	for (int i = 0; i < 4; ++i)
	{
		if (map[i] > avg)
			lo += map[i] - avg;
	}
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		int count[4] = {map[0], map[1], map[2], map[3]};
		if (!checkBalance(s, count, avg, mi))
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}