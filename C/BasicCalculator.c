#include <stdlib.h>

int doCalculate(char *s, int *index)
{
	int res = 0, flag = 1;
	for (; s[*index]; ++(*index))
	{
		if (s[*index] == ')')
			break;
		if (s[*index] == '(')
		{
			++(*index);
			res += flag * doCalculate(s, index);
		}
		else if (s[*index] == '+')
			flag = 1;
		else if (s[*index] == '-')
			flag = -1;
		else if (s[*index] != ' ')
		{
			int i = *index + 1;
			while (s[i] <= '9' && s[i] >= '0')
				++i;
			char tmp = s[i];
			s[i] = '\0';
			res += flag * atoi(&s[*index]);
			s[i] = tmp;
			*index = i - 1;
		}
	}
	return res;
}

int calculate(char *s)
{
	int index = 0;
	return doCalculate(s, &index);
}