#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int evalRPN(vector<string> &tokens)
	{
		stack<int> s;
		int first, second;
		for (auto &token : tokens)
		{
			if (token == "+")
			{
				first = s.top();
				s.pop();
				second = s.top();
				s.pop();
				s.push(first + second);
			}
			else if (token == "-")
			{
				first = s.top();
				s.pop();
				second = s.top();
				s.pop();
				s.push(second - first);
			}
			else if (token == "*")
			{
				first = s.top();
				s.pop();
				second = s.top();
				s.pop();
				s.push(first * second);
			}
			else if (token == "/")
			{
				first = s.top();
				s.pop();
				second = s.top();
				s.pop();
				s.push(second / first);
			}
			else
			{
				s.push(stoi(token));
			}
		}
		return s.top();
	}
};