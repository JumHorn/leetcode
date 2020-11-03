#include <string>
using namespace std;

/*
采用状态机解决这个问题
可能的状态
0. 空状态
1. 数字
2. 小数点后面数字，只能是数字和e
3. e后面数字，只能是数字
4. 符号状态
5. 小数点状态
6. e状态
7. e状态后面有符号位
8. 无效状态
state machine
							+/-		.		e		number
none				0		4		5		8		1
number				1		8		2		6		1
number and exponent	2		8		8		6		2
only number			3		8		8		8		3
sign				4		8		5		8		1
point				5		8		8		8		2
exponent			6		7		8		8		3
exponent and sign	7		8		8		8		3
invalid				8		8		8		8		8
*/

class Solution
{
public:
	bool isNumber(string s)
	{
		static int state[9][4] = {
			{4, 5, 8, 1},
			{8, 2, 6, 1},
			{8, 8, 6, 2},
			{8, 8, 8, 3},
			{8, 5, 8, 1},
			{8, 8, 8, 2},
			{7, 8, 8, 3},
			{8, 8, 8, 3},
			{8, 8, 8, 8}};
		s = trimmed(s);
		int n = 0; //for state 0
		for (int i = 0; i < (int)s.length(); ++i)
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
			if (n == 8)
				return false;
		}
		return n == 1 || n == 2 || n == 3;
	}

	string trimmed(string s)
	{
		int i = 0, j = s.length() - 1;
		while (i <= j && s[i] == ' ')
			i++;
		while (j >= i && s[j] == ' ')
			j--;
		if (i > j)
			return "";
		return s.substr(i, j - i + 1);
	}
};
