#include <stdlib.h>

int recursive(char *s, int res, int pre)
{
	if (!*s)
		return res;
	char *p = s;
	char op = *p++;
	while (*p && *p != '+' && *p != '-' && *p != '*' && *p != '/')
		++p;
	char old = *p;
	*p = '\0';
	int val = atoi(s + 1);
	*p = old;
	if (op == '+')
		return recursive(p, res + val, val);
	if (op == '-')
		return recursive(p, res - val, -val);
	if (op == '*')
		return recursive(p, res - pre + pre * val, pre * val);
	return recursive(p, res - pre + pre / val, pre / val);
}

int calculate(char *s)
{
	char *p = s, c;
	while (*p && *p != '+' && *p != '-' && *p != '*' && *p != '/')
		++p;
	c = *p;
	*p = '\0';
	int val = atoi(s);
	*p = c;
	return recursive(p, val, val);
}