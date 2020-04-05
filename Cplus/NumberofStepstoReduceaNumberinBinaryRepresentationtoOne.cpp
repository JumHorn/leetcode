#include <string>
using namespace std;

class Solution
{
public:
	int numSteps(string s)
	{
		int i = s.length() - 1, res = 0;
		while (i > 0)
		{
			if (s[i] == '0')
				--i;
			else
			{
				while (i >= 0 && s[i] == '1')
				{
					--i;
					++res;
				}
				if (i > 0)
					s[i] = '1';
			}
			++res;
		}
		return res;
	}
};
