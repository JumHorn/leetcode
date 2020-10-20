#include <stdlib.h>

int equalSubstring(char *s, char *t, int maxCost)
{
	int i = 0, j = 0, cost = 0;
	for (; s[j]; ++j)
	{
		cost += abs(s[j] - t[j]);
		if (cost > maxCost)
		{
			cost -= abs(s[i] - t[i]);
			++i;
		}
	}
	return j - i;
}