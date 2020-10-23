#include <string.h>

int lengthOfLastWord(char* s)
{
	int i = strlen(s), j = 0;
	for (--i; i >= 0 && s[i] == ' ';)
		--i;
	for (j = i; j >= 0 && s[j] != ' ';)
		--j;
	return i - j;
}
