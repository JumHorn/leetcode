#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int calPoints(vector<string> &ops)
	{
		stack<int> s;
		for (auto &op : ops)
		{
			if (op == "D")
				s.push(s.top() * 2);
			else if (op == "C")
				s.pop();
			else if (op == "+")
			{
				int a = s.top();
				s.pop();
				int b = s.top();
				s.pop();
				s.push(b);
				s.push(a);
				s.push(a + b);
			}
			else
				s.push(stoi(op));
		}
		int res = 0;
		while (!s.empty())
		{
			res += s.top();
			s.pop();
		}
		return res;
	}
};