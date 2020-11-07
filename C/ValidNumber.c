#include <stdbool.h>
#include <string.h>

/*
采用状态机解决这个问题
可能的状态
0. 无效状态
1. 空状态或起始状态
2. 数字
3. 小数点后面数字，只能是数字和e
4. e后面数字，只能是数字
5. 符号状态
6. 小数点状态
7. e状态
8. e状态后面有符号位

state machine				+/-		.		e		number
invalid				0		0		0		0		0
none start			1		5		6		0		2
number				2		0		3		7		2
number and exponent	3		0		0		7		3
only number			4		0		0		0		4
sign				5		0		6		0		2
point				6		0		0		0		3
exponent			7		8		0		0		4
exponent and sign	8		0		0		0		4
*/

char *trimmed(char *s)
{
	int i = 0, j = strlen(s) - 1;
	while (i <= j && s[i] == ' ')
		++i;
	while (j >= i && s[j] == ' ')
		--j;
	if (i > j)
		return "";
	s[j + 1] = '\0';
	return &s[i];
}

bool isNumber(char *s)
{
	static int state[9][4] = {
		{0, 0, 0, 0},
		{5, 6, 0, 2},
		{0, 3, 7, 2},
		{0, 0, 7, 3},
		{0, 0, 0, 4},
		{0, 6, 0, 2},
		{0, 0, 0, 3},
		{8, 0, 0, 4},
		{0, 0, 0, 4}};
	s = trimmed(s);
	int n = 1; //for state 1
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == '-' || s[i] == '+')
			n = state[n][0];
		else if (s[i] == '.')
			n = state[n][1];
		else if (s[i] == 'e')
			n = state[n][2];
		else if (s[i] >= '0' && s[i] <= '9')
			n = state[n][3];
		else
			return false;
	}
	return n == 2 || n == 3 || n == 4;
}