#include <stdlib.h>

char* skipzero(char* s, int* value)
{
	char* p = s;
	while (*p && *p != '.')
		++p;
	if (*p != '\0')
		*p++ = '\0';
	*value = atoi(s);
	return p;
}

int compareVersion(char* version1, char* version2)
{
	int value1, value2, res = 0;
	while (*version1 && *version2)
	{
		version1 = skipzero(version1, &value1);
		version2 = skipzero(version2, &value2);
		if (value1 != value2)
		{
			res = (value1 < value2 ? -1 : 1);
			break;
		}
	}
	if (res != 0)
		return res;
	while (*version1)
	{
		version1 = skipzero(version1, &value1);
		if (value1 != 0)
			return 1;
	}
	while (*version2)
	{
		version2 = skipzero(version2, &value2);
		if (value2 != 0)
			return -1;
	}
	return res;
}
