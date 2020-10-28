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
		for (int i = 0; i < (int)tokens.size(); i++)
		{
			if (tokens[i] == "+")
			{
				first = s.top();
				s.pop();
				second = s.top();
				s.pop();
				s.push(first + second);
			}
			else if (tokens[i] == "-")
			{
				first = s.top();
				s.pop();
				second = s.top();
				s.pop();
				s.push(second - first);
			}
			else if (tokens[i] == "*")
			{
				first = s.top();
				s.pop();
				second = s.top();
				s.pop();
				s.push(first * second);
			}
			else if (tokens[i] == "/")
			{
				first = s.top();
				s.pop();
				second = s.top();
				s.pop();
				s.push(second / first);
			}
			else
			{
				s.push(stoi(tokens[i]));
			}
		}
		return s.top();
	}
};