#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *recursive(char *s, int *index)
{
	char *res = (char *)malloc(sizeof(char) * 2000);
	memset(res, 0, sizeof(char) * 2000);
	int resSize = 0;
	while (s[*index] && s[*index] != ']')
	{
		if (!isdigit(s[*index]))
			res[resSize++] = s[(*index)++];
		else
		{
			int n = 0;
			for (; isdigit(s[*index]); ++*index)
				n = n * 10 + s[*index] - '0';

			++*index; //'['
			char *data = recursive(s, index);
			++*index; // ']'

			for (; n > 0; --n)
				resSize += sprintf(&res[resSize], "%s", data);
			//free(data);
		}
	}
	return res;
}

char *decodeString(char *s)
{
	int index = 0;
	return recursive(s, &index);
}