#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checkValid(char *num, long first, long second)
{
	if (!*num)
		return true;
	char str[35] = {0};
	long third = first + second;
	sprintf(str, "%ld", third);
	int i;
	for (i = 0; str[i]; ++i)
	{
		if (str[i] != num[i])
			break;
	}
	if (str[i] == '\0')
	{
		first = second;
		second = third;
		return checkValid(num + i, first, second);
	}
	return false;
}

bool isAdditiveNumber(char *num)
{
	int len = strlen(num);
	if (len < 3)
		return false;
	long first = 0, second = 0;
	for (int i = 0; i < len / 2; ++i)
	{
		char tmp = num[i + 1];
		num[i + 1] = '\0';
		first = atol(num);
		num[i + 1] = tmp;

		for (int j = i + 1; j <= (len - i - 1) / 2 + i; ++j)
		{
			tmp = num[j + 1];
			num[j + 1] = '\0';
			second = atol(num + i + 1);
			num[j + 1] = tmp;
			if (checkValid(num + j + 1, first, second))
				return true;

			if (num[i + 1] == '0')
				break;
		}

		if (num[0] == '0')
			break;
	}
	return false;
}