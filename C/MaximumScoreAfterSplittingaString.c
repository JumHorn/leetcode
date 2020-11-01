#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxScore(char* s)
{
	int res = 0, zero = 0, one = 0, N = 0;
	for (; s[N]; ++N)
		s[N] == '0' ? ++zero : ++one;
	int left = 0, right = one;
	for (int i = 0; i < N - 1; ++i)
	{
		s[i] == '0' ? ++left : --right;
		res = max(res, left + right);
	}
	return res;
}
