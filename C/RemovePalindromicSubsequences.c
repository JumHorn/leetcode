#include <string.h>

int removePalindromeSub(char* s)
{
	if (!*s)
		return 0;
	for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j)
	{
		if (s[i] != s[j])
			return 2;
	}
	return 1;
}
