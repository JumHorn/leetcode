#include <stdbool.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int lengthLongestPath(char *input)
{
	int stack[100] = {0}, top = 0, res = 0;
	while (*input)
	{
		int tab = 0;
		while (*input == '\t')
		{
			++input;
			++tab;
		}
		while (tab < top)
			--top;
		int count = 0;
		bool file = false;
		while (*input && *input != '\n')
		{
			if (*input++ == '.')
				file = true;
			++count;
		}
		if (*input)
			++input;
		if (file)
			res = max(res, stack[top] + count);
		else
		{
			stack[top + 1] = count + stack[top] + 1;
			++top;
		}
	}
	return res;
}