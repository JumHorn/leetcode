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

				if (ops.size() > 0 && ops.top() != '(')
				{
					auto op = ops.top();
					ops.pop();
					auto [p1, q1] = state.top();
					state.pop();
					auto [p2, q2] = state.top();
					state.pop();
					if (op == '&')
						state.push({min(p1, p2), min(q1 + q2, 1 + min(q1, q2))});
					else
						state.push({min(p1 + p2, 1 + min(p1, p2)), min(q1, q2)});
				}
			}
			else
				ops.push(c);
		}
		return max(state.top().first, state.top().second);
	}
};