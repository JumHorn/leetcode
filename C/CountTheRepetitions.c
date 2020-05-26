#include <string.h>

int getMaxRepetitions(char *s1, int n1, char *s2, int n2)
{
	int map[26] = {0};
	char *p1 = s1, *p2 = s2;
	while (*p2)
	{
		map[*p2 - 'a'] = 1;
		++p2;
	}
	while (*p1)
	{
		map[*p1 - 'a'] = 0;
		++p1;
	}
	for (int i = 0; i < 26; i++)
	{
		if (map[i] != 0)
			return 0;
	}
	int len2 = strlen(s2);
	int count[len2 + 1], seen[len2], res = 0;
	memset(count, 0, sizeof(count));
	memset(seen, -1, sizeof(seen));

	p2 = s2;
	for (int i = 0; i < n1; i++)
	{
		p1 = s1;
		while (*p1)
		{
			if (*p1 == *p2)
			{
				++p2;
			}
			if (!*p2)
			{
				++res;
				p2 = s2;
			}
			++p1;
		}
		count[i] = res;
		int k = seen[p2 - s2];
		if (k != -1)
		{
			int pre = count[k];
			int repeat = (count[i] - count[k]) * ((n1 - k - 1) / (i - k));
			int remain = count[k + (n1 - k - 1) % (i - k)] - count[k];
			return (pre + repeat + remain) / n2;
		}
		seen[p2 - s2] = i;
	}
	return res / n2;
}