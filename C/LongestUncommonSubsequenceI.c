#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int findLUSlength(char* a, char* b)
{
	if (strcmp(a, b) == 0)
		return -1;
	int alen = strlen(a), blen = strlen(b);
	return max(alen, blen);
}
