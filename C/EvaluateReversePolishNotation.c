#include <stdlib.h>
#include <string.h>

int evalRPN(char **tokens, int tokensSize)
{
	int stack[tokensSize], top = -1;
	int first, second;
	for (int i = 0; i < tokensSize; ++i)
	{
		if (strcmp(tokens[i], "+") == 0)
		{
			first = stack[top--];
			second = stack[top--];
			stack[++top] = first + second;
		}
		else if (strcmp(tokens[i], "-") == 0)
		{
			first = stack[top--];
			second = stack[top--];
			stack[++top] = second - first;
		}
		else if (strcmp(tokens[i], "*") == 0)
		{
			first = stack[top--];
			second = stack[top--];
			stack[++top] = first * second;
		}
		else if (strcmp(tokens[i], "/") == 0)
		{
			first = stack[top--];
			second = stack[top--];
			stack[++top] = second / first;
		}
		else
			stack[++top] = atoi(tokens[i]);
	}
	return stack[0];
}