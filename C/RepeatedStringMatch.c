#include <string.h>

int repeatedStringMatch(char* a, char* b)
{
	int Alen = strlen(a);
	for (int i = 0; i < Alen; ++i)
	{
		int j = 0;
		while (b[j] && a[(i + j) % Alen] == b[j])
			++j;
		if (!b[j])
			return (i + j - 1) / Alen + 1;
	}
	return -1;
}
