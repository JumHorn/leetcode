#include <limits.h>
#include <stdbool.h>

int myAtoi(char *str)
{
	int res = 0;
	while (*str == ' ')
		++str;
	if (!*str)
		return 0;
	bool negative = false;
	if (*str == '-')
	{
		++str;
		negative = true;
	}
	else if (*str == '+')
		++str;

	for (; *str && *str >= '0' && *str <= '9'; ++str)
	{
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && *str - '0' > INT_MAX % 10))
			return negative ? INT_MIN : INT_MAX;
		res = res * 10 + (*str - '0'); //must with parenthesis,to avoid (res * 10 + *str) overflow
	}
	return negative ? -res : res;
}