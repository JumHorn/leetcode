#include <stdlib.h>
#include <string.h>

int cmp(const void *lhs, const void *rhs)
{
	return strcmp(*(char **)lhs, *(char **)rhs);
}

int numUniqueEmails(char **emails, int emailsSize)
{
	for (int k = 0; k < emailsSize; ++k)
	{
		int i = 0, j = 0;
		for (; emails[k][j] != '+' && emails[k][j] != '@'; ++j)
		{
			if (emails[k][j] != '.')
				emails[k][i++] = emails[k][j];
		}
		while (emails[k][j] != '@')
			++j;
		for (; emails[k][j]; ++i, ++j)
			emails[k][i] = emails[k][j];
		emails[k][i] = '\0';
	}
	qsort(emails, emailsSize, sizeof(char *), cmp);
	int res = 0;
	for (int i = 1, j = 0; i <= emailsSize; ++i)
	{
		if (i == emailsSize || strcmp(emails[i], emails[j]) != 0)
		{
			++res;
			j = i;
		}
	}
	return res;
}