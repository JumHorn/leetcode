#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *solveEquation(char *equation)
{
	char *res = (char *)malloc(sizeof(char) * 20);
	int coefficient = 0, y = 0, val = 0, sign = 1;
	char *p = equation;
	while (*p)
	{
		if (sscanf(p, "%d", &val) != 1)
		{
			if (*p != 'x' && *p != '=')
				++p;
			val = ((p != equation && *(p - 1) == '-') ? -1 : 1);
		}
		else
			++p;
		while (*p && isdigit(*p))
			++p;
		if (*p == 'x')
		{
			coefficient += val * sign;
			++p;
		}
		else if (*p == '=')
		{
			if (*(p - 1) != 'x')
				y += val * sign;
			sign = -1;
			++p;
		}
		else
			y += val * sign;
	}
	if (coefficient == 0)
		y == 0 ? sprintf(res, "Infinite solutions") : sprintf(res, "No solution");
	else
		sprintf(res, "x=%d", -y / coefficient);
	return res;
}