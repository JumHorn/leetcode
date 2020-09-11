#include <climits>
#include <string>
using namespace std;

class Solution
{
public:
	int myAtoi(string str)
	{
		int N = str.length(), i = 0;
		long res = 0;
		while (i < N && str[i] == ' ')
			++i;
		if (i == N)
			return 0;
		bool negative = false, overflow = false;
		if (str[i] == '-')
		{
			++i;
			negative = true;
		}
		else if (str[i] == '+')
			++i;

		for (; i < N && str[i] >= '0' && str[i] <= '9'; ++i)
		{
			res = res * 10 + str[i] - '0';
			if (res > INT_MAX)
			{
				overflow = true;
				break;
			}
		}
		if (overflow)
			return negative ? INT_MIN : INT_MAX;
		return negative ? -res : res;
	}
};
