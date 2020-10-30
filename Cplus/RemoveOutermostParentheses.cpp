#include <string>
using namespace std;

class Solution
{
public:
	string removeOuterParentheses(string S)
	{
		int count = 0, i = 0;
		for (auto c : S)
		{
			if (c == '(')
			{
				if (count++ != 0)
					S[i++] = c;
			}
			else if (c == ')')
			{
				if (--count != 0)
					S[i++] = c;
			}
		}
		return S.substr(0, i);
	}
};