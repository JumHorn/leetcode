#include <stdbool.h>
#include <string.h>

bool isAnagram(char *s, char *t)
{
	if (strlen(s) != strlen(t))
		return false;
	int count[26] = {0};
	for (int i = 0; s[i]; ++i)
		++count[s[i] - 'a'];
	for (int i = 0; t[i]; ++i)
	{
		if (--count[t[i] - 'a'] < 0)
			return false;
	}
	return true;
}