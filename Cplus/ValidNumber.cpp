#include <string>
using namespace std;

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

class Solution
{
public:
	bool isNumber(string s)
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
		for (auto c : s)
		{
			if (c == '-' || c == '+')
				n = state[n][0];
			else if (c == '.')
				n = state[n][1];
			else if (c == 'e')
				n = state[n][2];
			else if (c >= '0' && c <= '9')
				n = state[n][3];
			else
				return false;
		}
		return n == 2 || n == 3 || n == 4;
	}

	string trimmed(string s)
	{
		int i = 0, j = (int)s.length() - 1;
		while (i <= j && s[i] == ' ')
			++i;
		while (j >= i && s[j] == ' ')
			--j;
		if (i > j)
			return "";
		return s.substr(i, j - i + 1);
	}
};