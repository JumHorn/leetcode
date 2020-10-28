#include <stdlib.h>

int calPoints(char** ops, int opsSize)
{
	int stack[1000], top = -1;
	for (int i = 0; i < opsSize; ++i)
	{
		if (ops[i][0] == 'D')
		{
			stack[top + 1] = stack[top] * 2;
			++top;
		}
		else if (ops[i][0] == 'C')
			--top;
		else if (ops[i][0] == '+')
		{
			stack[top + 1] = stack[top] + stack[top - 1];
			++top;
		}
		else
			stack[++top] = atoi(ops[i]);
	}
	int res = 0;
	for (; top >= 0; --top)
		res += stack[top];
	return res;
}
