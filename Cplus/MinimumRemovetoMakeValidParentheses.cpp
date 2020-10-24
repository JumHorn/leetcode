#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
	string minRemoveToMakeValid(string s)
	{
		stack<int> stk; //index of parenthese
		int N = s.length(), index = 0;
		for (int i = 0; i < N; ++i)
		{
			if (s[i] == ')')
			{
				if (!stk.empty())
				{
					stk.pop();
					s[index++] = s[i];
				}
			}
			else
			{
				if (s[i] == '(')
					stk.push(index);
				s[index++] = s[i];
			}
		}
		if (stk.empty())
			return s.substr(0, index);
		int len = index;
		for (int i = index - 1; i >= 0; --i)
		{
			if (stk.empty() || stk.top() != i)
				s[--index] = s[i];
			else
				stk.pop();
		}
		return s.substr(index, len - index);
	}
};