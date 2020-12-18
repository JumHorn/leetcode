#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int characterReplacement(char *s, int k)
{
	int window = 0, maxsame = 0;
	int hash[26] = {0};
	for (int i = 0; s[i]; ++i)
	{
		++hash[s[i] - 'A'];
		maxsame = max(maxsame, hash[s[i] - 'A']);
		if (window - maxsame < k)
			++window;
		else
			--hash[s[i - window] - 'A'];
	}
	return window;
}