#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define swap(a, b) ((a) != (b) && ((a) ^= (b) ^= (a) ^= (b)))

bool isVowel(char c)
{
	c = tolower(c);
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char *reverseVowels(char *s)
{
	int i = 0, j = strlen(s) - 1;
	while (i < j)
	{
		if (!isVowel(s[i]))
			++i;
		else if (!isVowel(s[j]))
			--j;
		else
		{
			swap(s[i], s[j]);
			++i;
			--j;
		}
	}
	return s;
}