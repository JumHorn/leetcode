#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct pair
{
	int divider;
	int dividend;
} pair;

int gcd(long x, long y)
{
	return x == 0 ? y : gcd(y % x, x);
}

int substrToInteger(char *s, int len)
{
	char old = s[len];
	s[len] = '\0';
	int res = atoi(s);
	s[len] = old;
	return res;
}

int find(char *s, char c)
{
	char sub[2] = {0};
	sub[0] = c;
	char *p = strstr(s, sub);
	if (p == NULL)
		return strlen(s);
	return p - s;
}

pair rationalTofraction(char *s)
{
	pair res;
	int integer, nonrepeat, repeat, base = 0, i = 0, j = 0, N = strlen(s);
	j += find(&s[j], '.');
	integer = substrToInteger(&s[i], j - i);
	if (j >= N)
	{
		res.dividend = integer;
		res.divider = 1;
		return res;
	}

	i = ++j;
	j += find(&s[j], '(');
	if (i == j)
		nonrepeat = 0;
	else
		nonrepeat = substrToInteger(&s[i], j - i);
	base += j - i;
	long dividend = nonrepeat + integer * pow(10, j - i);

	int divider;
	if (j + 1 >= N)
	{
		divider = pow(10, base);
		int g = gcd(dividend, divider);
		res.dividend = dividend / g;
		res.divider = divider / g;
		return res;
	}

	i = ++j;
	j += find(&s[j], ')');
	repeat = substrToInteger(&s[i], j - i);
	dividend = dividend * pow(10, j - i) + repeat - dividend;
	divider = pow(10, base + j - i) - pow(10, base);
	int g = gcd(dividend, divider);
	res.dividend = dividend / g;
	res.divider = divider / g;
	return res;
}

bool isRationalEqual(char *S, char *T)
{
	pair s = rationalTofraction(S);
	pair t = rationalTofraction(T);
	return s.dividend == t.dividend && s.divider == t.divider;
}