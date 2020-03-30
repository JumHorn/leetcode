#include <string.h>

bool isMatch(char* s, char* p)
{
	if (!*s && !*p)
		return true;
	if (!*p)
		return false;
	if (!*s)
	{
		while (*p && *p == '*')
			++p;
		return !*p;
	}
	if (*p == '?' || *p == *s)
		return isMatch(s + 1, p + 1);
	if (*p == '*')
		return isMatch(s + 1, p) || isMatch(s, p + 1) || isMatch(s + 1, p + 1);
	return false;
}

