#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		unordered_map<char, char> m = {{')', '('}, {'}', '{'}, {']', '['}};
		stack<char> stk;
		for (auto c : s)
		{
			if (m.find(c) != m.end())
			{
				if (stk.empty() || stk.top() != m[c])
					return false;
				stk.pop();
			}
			else
				stk.push(c);
		}
		return stk.empty();
	}
};