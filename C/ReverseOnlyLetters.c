#include <ctype.h>
#include <string.h>

#define swap(a, b) ((a) != (b) && ((a) ^= (b) ^= (a) ^= (b)))

char *reverseOnlyLetters(char *S)
{
	int i = 0, j = strlen(S) - 1;
	while (i < j)
	{
		if (!isalpha(S[i]))
			++i;
		else if (!isalpha(S[j]))
			--j;
		else
		{
			swap(S[i], S[j]);
			++i;
			--j;
		}
	}
	return S;
}