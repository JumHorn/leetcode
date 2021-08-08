#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
	int minSwaps(string s)
	{
		int N = s.length();
		stack<char> stk;
		for (auto c : s)
		{
			if (c == '[')
				stk.push(c);
			else
			{
				if (!stk.empty() && stk.top() != c)
					stk.pop();
				else
					stk.push(c);
			}
		}
		if (stk.size() == 0)
			return 0;
		int res = stk.size() / 2;
		return (res + 1) / 2;
	}
};