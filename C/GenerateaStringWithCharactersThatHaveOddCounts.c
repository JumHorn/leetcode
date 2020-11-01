#include <stdlib.h>
#include <string.h>

char* generateTheString(int n)
{
	char* res = (char*)malloc(sizeof(char) * (n + 1));
	res[n] = '\0';
	if (n % 2 == 1)
		memset(res, 'a', sizeof(char) * n);
	else
	{
		memset(res, 'a', sizeof(char) * (n - 1));
		res[n - 1] = 'b';
	}
	return res;
}
