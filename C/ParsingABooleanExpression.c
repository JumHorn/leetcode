#include <stdbool.h>
#include <string.h>

int nextExpr(char *expression, int left, int right)
{
	int parenthsis = 0, i = left;
	for (; i < right && (expression[i] != ',' || parenthsis != 0); ++i)
	{
		if (expression[i] == '(')
			++parenthsis;
		else if (expression[i] == ')')
			--parenthsis;
	}
	return i;
}

bool recursion(char *expression, int left, int right)
{
	bool res = true;
	if (expression[left] == '!')
		res = !recursion(expression, left + 2, right - 1);
	else if (expression[left] == '&')
	{
		for (int i = left + 2, j = left + 2; j < right && res; i = ++j)
		{
			j = nextExpr(expression, i, right);
			res = recursion(expression, i, j);
		}
	}
	else if (expression[left] == '|')
	{
		res = false;
		for (int i = left + 2, j = left + 2; j < right && !res; i = ++j)
		{
			j = nextExpr(expression, i, right);
			res = recursion(expression, i, j);
		}
	}
	else
		res = (expression[left] == 't');
	return res;
}

bool parseBoolExpr(char *expression)
{
	return recursion(expression, 0, strlen(expression));
}