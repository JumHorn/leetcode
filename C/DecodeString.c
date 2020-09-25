#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *recursive(char *s, int *index)
{
	char *res = (char *)malloc(sizeof(char) * 2000);
	memset(res, 0, sizeof(char) * 2000);
	int i = 0, len = strlen(s);
	while (*index < len && s[*index] != ']')
	{
		if (!isdigit(s[*index]))
			strncat(res, &s[(*index)++], 1);
		else
		{
			int n = 0;
			while (isdigit(s[*index]))
				n = n * 10 + s[(*index)++] - '0';

			++*index; //'['
			char *data = recursive(s, index);
			++*index; // ']'

			while (--n >= 0)
				strcat(res, data);
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