#include <stdbool.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int lengthOfLongestSubstring(char *s)
{
	if (!*s)
		return 0;
	int map[128] = {0}, res = 0;
	char *p = s;
	for (int i = 0; *p; ++p)
	{
		i = max(i, map[(int)*p]);
		map[(int)*p] = p - s + 1;
		res = max(res, p - s - i + 1);
	}
	return res;
}