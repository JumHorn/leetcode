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
		string res;
		while (!stk.empty())
		{
			int pre = stk.top();
			stk.pop();
			res = s.substr(pre + 1, index - pre - 1) + res;
			index = pre;
		}
		res = s.substr(0, index) + res;
		return res;
	}
};