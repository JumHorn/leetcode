#include <stdio.h>

int compress(char *chars, int charsSize)
{
	if (charsSize == 0)
		return 0;
	char pre = chars[0];
	int res = 0;
	for (int i = 1, j = 0; i <= charsSize; ++i)
	{
		if (i == charsSize || chars[i] != pre)
		{
			int count = i - j;
			chars[res++] = pre;
			if (count > 1)
			{
				char str[5];
				sprintf(str, "%d", count);
				for (int j = 0; str[j]; ++j)
					chars[res++] = str[j];
			}
			j = i;
		}
		if (i < charsSize)
			pre = chars[i];
	}
	return res;
}
