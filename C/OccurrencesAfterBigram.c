#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findOcurrences(char* text, char* first, char* second, int* returnSize)
{
	char pattern[25];
	int N = sprintf(pattern, "%s %s ", first, second);
	char** res = (char**)malloc(sizeof(char*) * 100);
	*returnSize = 0;
	for (char* substr = strstr(text, pattern); substr; substr = strstr(substr + N, pattern))
	{
		if (substr == text || *(substr - 1) == ' ')
		{
			char* p = strstr(substr + N, " ");
			char old;
			if (p)
			{
				old = *p;
				*p = '\0';
			}
			res[(*returnSize)++] = strdup(substr + N);
			if (p)
				*p = old;
		}
	}
	return res;
}
