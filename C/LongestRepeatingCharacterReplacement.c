#include <stdbool.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

bool check(char *s, int k, int window)
{
	int hash[26] = {0}, maxcount = 0;
	for (int i = 0; i < window; ++i)
		++hash[s[i] - 'A'];
	for (int i = 0; i < 26; ++i)
		maxcount = max(maxcount, hash[i]);
	if (window - maxcount <= k)
		return true;
	for (int i = window; s[i]; ++i)
	{
		++hash[s[i] - 'A'];
		--hash[s[i - window] - 'A'];
		maxcount = 0;
		for (int i = 0; i < 26; ++i)
			maxcount = max(maxcount, hash[i]);
		if (window - maxcount <= k)
			return true;
	}
	return false;
}

int characterReplacement(char *s, int k)
{
	int N = strlen(s);
	int lo = 0, hi = N;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (check(s, k, mi))
			lo = mi + 1;
		else
			hi = mi;
	}
	if (!check(s, k, lo))
		--lo;
	return lo;
}