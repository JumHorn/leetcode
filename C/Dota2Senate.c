#include <stdbool.h>

char *predictPartyVictory(char *senate)
{
	int skip = 0;
	while (true)
	{
		int r = 0, d = 0;
		char *p = senate, *q = senate;
		while (*p)
		{
			if (*p == 'R')
				--skip >= 0 ? *p = '.' : ++r;
			else
				++skip <= 0 ? *p = '.' : ++d;
			if (*p != '.')
				*q++ = *p;
			++p;
		}
		*q = '\0';
		if (d + skip <= 0)
			return "Radiant";
		if (r - skip <= 0)
			return "Dire";
	}
	return "";
}