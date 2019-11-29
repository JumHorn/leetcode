#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **removeComments(char **source, int sourceSize, int *returnSize)
{
	bool skip = false;
	char *head;
	int headrow;
	for (int i = 0; i < sourceSize; i++)
	{
		char *p = source[i];
		while (*p)
		{
			if (skip)
			{
				if (*p == '*')
				{
					++p;
					if (*p && *p == '/')
					{
						++p;
						while (*p)
							*head++ = *p++;
						*head = '\0';
						skip = false;
						i = headrow - 1;
					}
				}
				else if (p == source[i])
				{
					*p = '\0';
					++p;
				}
				else
					++p;
			}
			else
			{
				if (*p == '/')
				{
					++p;
					if (*p && *p == '/')
					{
						*(p - 1) = '\0';
						break;
					}
					if (*p && *p == '*')
					{
						*(p - 1) = '\0';
						head = p - 1;
						headrow = i;
						skip = true;
						++p;
					}
				}
				else
					++p;
			}
		}
	}

	*returnSize = 0;
	for (int i = 0; i < sourceSize; i++)
		if (source[i][0] != '\0')
			(*returnSize)++;
	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int i = 0, j = 0; i < sourceSize; i++)
		if (source[i][0] != '\0')
		{
			int len = strlen(source[i]);
			res[j] = (char *)malloc(sizeof(char) * (len + 1));
			memcpy(res[j++], source[i], len + 1);
		}
	return res;
}