#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int maxNumberOfBalloons(char *text)
{
	int map[26] = {0};
	while (*text)
		++map[*text++ - 'a'];
	int res = INT_MAX;
	map['l' - 'a'] /= 2;
	map['o' - 'a'] /= 2;
	char *balloon = "balloon";
	for (char *p = balloon; *p; ++p)
		res = min(res, map[*p - 'a']);
	return res;
}