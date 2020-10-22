#include <algorithm>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
	string reverseParentheses(string s)
	{
		stack<pair<int, string>> stk; //{left parenthese count,str}
		stk.push({-1, ""});
		int left = 0, pos = 0, N = s.length(); //last parentheses pos
		for (int i = 0; i <= N; ++i)
		{
			if (s[i] == ')' || i == N)
			{
				string val = s.substr(pos, i - pos);
				if (left % 2 == 1)
					reverse(val.begin(), val.end());
				stk.push({left, val});
				pos = i + 1;
				--left;

				while (left < stk.top().first)
				{
					val = stk.top().second;
					stk.pop();
					if (stk.top().first % 2 == 1)
						stk.top().second = val + stk.top().second;
					else
						stk.top().second += val;
				}
			}
			else if (s[i] == '(')
			{
				string val = s.substr(pos, i - pos);
				if (left % 2 == 1)
					reverse(val.begin(), val.end());
				stk.push({left, val});
				pos = i + 1;
				++left;
			}
		}
		return stk.top().second;
	}
};