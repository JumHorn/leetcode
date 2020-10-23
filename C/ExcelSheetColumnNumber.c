#include <string.h>

int titleToNumber(char *s)
{
	int N = strlen(s), pow = 26, res = 0;
	long base = 1;
	for (int i = N - 1; i >= 0; --i)
	{
		res += (s[i] - 'A' + 1) * base;
		base *= pow;
	}
	return res;
}