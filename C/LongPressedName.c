#include <stdbool.h>

bool isLongPressedName(char *name, char *typed)
{
	char *p = name, *q = typed;
	for (; *q; ++q)
	{
		if (*p == *q)
			++p;
		else if (p == name || *q != *(p - 1))
			return false;
	}
	return !*p;
}