#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxLengthBetweenEqualCharacters(char* s)
{
	int hash[26], res = 0;
	memset(hash, -1, sizeof(hash));
	for (int i = 0; s[i]; ++i)
	{
		if (hash[s[i] - 'a'] == -1)
			hash[s[i] - 'a'] = i;
		res = max(res, i - hash[s[i] - 'a']);
	}
	return res - 1;
}
