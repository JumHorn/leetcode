#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int x, int y)
{
	return x == 0 ? y : gcd(y % x, x);
}

char *fractionAddition(char *expression)
{
	char *res = (char *)malloc(sizeof(char) * 25);
	char *p = expression;
	int A = 0, B = 1, a, b;
	while (sscanf(p, "%d/%d", &a, &b) != EOF)
	{
		while (*p != '/')
			++p;
		while (*p && *p != '+' && *p != '-')
			++p;
		A = A * b + a * B;
		B *= b;
		int g = abs(gcd(A, B));
		A /= g;
		B /= g;
	}
	sprintf(res, "%d/%d", A, B);
	return res;
}