#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s)
{
	int i = 0, j = strlen(s) - 1;
	while (i < j)
	{
		if (!isalnum(s[i]))
			++i;
		else if (!isalnum(s[j]))
			--j;
		else
		{
			if (toupper(s[i]) != toupper(s[j]))
				return false;
			++i;
			--j;
		}
	}
	return true;
}
