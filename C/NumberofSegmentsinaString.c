#include <string.h>

int countSegments(char *s)
{
	int res = 0;
	for (char *token = strtok(s, " "); token; token = strtok(NULL, " "))
		++res;
	return res;
}