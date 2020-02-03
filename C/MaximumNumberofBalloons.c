#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int maxNumberOfBalloons(char* text)
{
	int map[26] = {0};
	while (*text)
		++map[*text++ - 'a'];
	int res = INT_MAX;
	map['l' - 'a'] /= 2;
	map['o' - 'a'] /= 2;
	res = min(res, map['b' - 'a']);
	res = min(res, map['a' - 'a']);
	res = min(res, map['l' - 'a']);
	res = min(res, map['o' - 'a']);
	res = min(res, map['n' - 'a']);
	return res;
}

