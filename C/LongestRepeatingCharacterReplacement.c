#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int characterReplacement(char *s, int k)
{
	int i = 0, j = 0, maxsame = 0;
	int hash[26] = {0};
	for (; s[j]; ++j)
	{
		++hash[s[j] - 'A'];
		maxsame = max(maxsame, hash[s[j] - 'A']);
		if (j - i - maxsame >= k)
			--hash[s[i++] - 'A'];
	}
	return j - i;
}