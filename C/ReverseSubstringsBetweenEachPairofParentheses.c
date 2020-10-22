#include <stdlib.h>
#include <string.h>

char* reverseParentheses(char* s)
{
	int N = strlen(s);
	int stack[N], top = -1, pair[N];
	for (int i = 0; i < N; ++i)
	{
		if (s[i] == '(')
			stack[++top] = i;
		if (s[i] == ')')
		{
			int j = stack[top--];
			pair[i] = j;
			pair[j] = i;
		}
	}
	char* res = (char*)malloc(sizeof(char) * (N + 1));
	int resSize = 0;
	for (int i = 0, d = 1; i < N; i += d)
	{
		if (s[i] == '(' || s[i] == ')')
		{
			i = pair[i];
			d = -d;
		}
		else
			res[resSize++] = s[i];
	}
	res[resSize] = '\0';
	return res;
}
