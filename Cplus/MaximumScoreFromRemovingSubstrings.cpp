#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumGain(string s, int x, int y)
	{
		return x <= y ? gain(s, 'a', 'b', x, y) : gain(s, 'b', 'a', y, x);
	}

	int gain(string &s, char a, char b, int x, int y)
	{
		stack<char> stk1, stk2;
		int res = 0;
		for (auto c : s)
		{
			if (c == a && !stk1.empty() && stk1.top() == b) //ba
			{
				stk1.pop();
				res += y;
			}
			else
				stk1.push(c);
		}
		//process ab
		while (!stk1.empty())
		{
			char c = stk1.top();
			stk1.pop();

			if (c == a && !stk2.empty() && stk2.top() == b)
			{
				stk2.pop();
				res += x;
			}
			else
				stk2.push(c);
		}
		return res;
	}
};