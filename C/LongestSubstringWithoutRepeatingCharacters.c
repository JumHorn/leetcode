#include <stdbool.h>
#include <string.h>

bool checkRepeat(int* map)
{
	for (int i = 0; i < 128; i++)
	{
		if (map[i] > 1)
			return false;
	}
	return true;
}

int lengthOfLongestSubstring(char* s)
{
	if (!*s)
		return 0;
	int map[128] = {0};
	int res = 2, len = strlen(s);
	++map[(int)*s];
	for (int i = 1; i < len; i++)
	{
		++map[(int)s[i]];
		if (checkRepeat(map))
			++res;
		else
			--map[(int)s[i - res + 1]];
	}
	return res - 1;
}
