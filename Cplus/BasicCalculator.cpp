#include <string>
using namespace std;

class Solution
{
public:
	int calculate(string s)
	{
		int index = 0;
		return doCalculate(s, index);
	}

	int doCalculate(string &s, int &index)
	{
		int res = 0, flag = 1;
		while (index < (int)s.length())
		{
			if (s[index] == ')')
				break;
			if (s[index] == '(')
				res += flag * doCalculate(s, ++index);
			else if (s[index] == '+')
				flag = 1;
			else if (s[index] == '-')
				flag = -1;
			else if (s[index] != ' ')
			{
				int i = index + 1;
				while (s[i] <= '9' && s[i] >= '0')
					i++;
				char tmp = s[i];
				s[i] = '\0';
				res += flag * atoi(&s[index]);
				s[i] = tmp;
				index = i - 1;
			}
			++index;
		}
		return res;
	}
};