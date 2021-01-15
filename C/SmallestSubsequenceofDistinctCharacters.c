#include <stdlib.h>
#include <string.h>

char *smallestSubsequence(char *text)
{
	char count[26] = {0}, *p = text;
	while (*p)
		++count[*p++ - 'a'];
	char *stack = (char *)malloc(sizeof(char) * 27);
	memset(stack, 0, sizeof(char) * 27);
	int top = -1, seen[26] = {0};
	for (p = text; *p; ++p)
	{
		if (seen[*p - 'a'] == 0)
		{
			while (top != -1 && count[stack[top] - 'a'] != 0 && stack[top] > *p)
			{
				seen[stack[top] - 'a'] = 0;
				--top;
			}
			stack[++top] = *p;
			seen[*p - 'a'] = 1;
		}
		--count[*p - 'a'];
	}
	stack[++top] = '\0';
	return stack;
}