#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
	int minOperationsToFlip(string expression)
	{
		stack<pair<int, int>> state; //{operations for result 0, operations for result 1}
		stack<char> ops;
		for (auto c : expression)
		{
			if (c == '0' || c == '1' || c == ')')
			{
				if (c == '0')
					state.push({0, 1});
				else if (c == '1')
					state.push({1, 0});
				else
					ops.pop();

				if (!ops.empty() && ops.top() != '(')
				{
					auto op = ops.top();
					ops.pop();
					auto [p0, p1] = state.top();
					state.pop();
					auto [q0, q1] = state.top();
					state.pop();
					if (op == '&')
						state.push({min(p0, q0), min(p1 + q1, 1 + min(p1, q1))});
					else
						state.push({min(p0 + q0, 1 + min(p0, q0)), min(p1, q1)});
				}
			}
			else
				ops.push(c);
		}
		return max(state.top().first, state.top().second);
	}
};