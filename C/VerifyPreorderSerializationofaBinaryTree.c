#include <stdbool.h>

bool isValidSerialization(char* preorder)
{
	int degree = 1;
	while (*preorder)
	{
		if (--degree < 0)
			return false;
		char* p = preorder;
		while (*p && *p != ',')
			++p;
		if (*preorder != '#')
			degree += 2;
		if (*p)
			++p;
		preorder = p;
	}
	return degree == 0;
}
