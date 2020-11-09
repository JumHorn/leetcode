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
		int res = 0, flag = 1, N = s.length();
		for (; index < N; ++index)
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
				while (i < N && s[i] <= '9' && s[i] >= '0')
					++i;
				res += flag * stoi(s.substr(index, i - index));
				index = i - 1;
			}
		}
		return res;
	}
};