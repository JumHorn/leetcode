#include <limits.h>

char *minWindow(char *s, char *t)
{
	int map[256] = {0}, count = 0, window = INT_MAX;
	char *end = t, *begin, *res;
	while (*end)
	{
		++map[(int)*end];
		++count;
		++end;
	}
	begin = end = s;
	while (*end)
	{
		if (--map[(int)*end++] >= 0)
			--count;
		if (end - begin >= window && ++map[(int)*begin++] > 0)
			++count;
		if (count == 0)
		{
			while (begin < end && ++map[(int)*begin] <= 0)
				++begin;
			++count;
			window = end - begin;
			res = begin++;
		}
	}
	if (window == INT_MAX)
		return "";
	*(res + window) = '\0';
	return res;
}