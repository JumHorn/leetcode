#include <limits.h>
#include <string.h>

char *minWindow(char *s, char *t)
{
	int map['z' - 'A' + 1] = {0};
	for (int i = 0; t[i]; ++i)
		++map[t[i] - 'A'];
	int count = strlen(t), start = -1, window = INT_MAX;
	for (int i = 0, j = 0; s[i]; ++i)
	{
		if (--map[s[i] - 'A'] >= 0)
			--count;
		for (; count == 0; ++j)
		{
			if (i - j + 1 < window)
			{
				start = j;
				window = i - j + 1;
			}
			if (++map[s[j] - 'A'] > 0)
				++count;
		}
	}
	if (start < 0)
		return "";
	s[start + window] = '\0';
	return &s[start];
}