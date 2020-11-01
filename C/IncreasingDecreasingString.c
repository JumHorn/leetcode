#include <stdlib.h>
#include <string.h>

char* sortString(char* s)
{
	int count[26] = {0}, N = 0;
	for (; s[N]; ++N)
		++count[s[N] - 'a'];
	char* res = (char*)malloc(sizeof(char) * (N + 1));
	res[N] = '\0';
	for (int i = 0; i < N;)
	{
		for (int j = 0; j < 26; ++j)
		{
			if (count[j] > 0)
			{
				--count[j];
				res[i++] = j + 'a';
			}
		}
		for (int j = 25; j >= 0; --j)
		{
			if (count[j] > 0)
			{
				--count[j];
				res[i++] = j + 'a';
			}
		}
	}
	return res;
}
