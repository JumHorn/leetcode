#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
	string minRemoveToMakeValid(string s)
	{
		stack<int> stk; //index of parenthese
		int N = s.length();
		for (int i = 0; i < N; ++i)
		{
			if (s[i] == '(')
				stk.push(i);
			else if (s[i] == ')')
			{
				if (stk.empty())
					s[i] = '*';
				else
					stk.pop();
			}
		}
		for (; !stk.empty(); stk.pop())
			s[stk.top()] = '*';
		int j = 0;
		for (int i = 0; i < N; ++i)
		{
			if (s[i] != '*')
				s[j++] = s[i];
		}
		return s.substr(0, j);
	}
};