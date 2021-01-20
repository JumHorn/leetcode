#include <stdbool.h>

/*
Q 1
R 2
E 3
W 0
*/
#define HASH(x) (((x) % 7) - 3)
#define min(a, b) (((a) < (b)) ? (a) : (b))

bool lowerThanAvg(int *count, int avg)
{
	for (int i = 0; i < 4; ++i)
	{
		if (count[i] > avg)
			return false;
	}
	return true;
}

int balancedString(char *s)
{
	int map[4] = {0}, N = 0;
	for (; s[N]; ++N)
		++map[HASH(s[N])];
	int avg = N / 4, res = avg * 3;
	for (int i = 0, j = 0; j < N; ++j)
	{
		for (--map[HASH(s[j])]; i < N && lowerThanAvg(map, avg); ++i)
		{
			res = min(res, j - i + 1);
			++map[HASH(s[i])];
		}
	}
	return res;
}