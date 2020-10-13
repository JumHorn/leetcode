#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
	int scoreOfParentheses(string S)
	{
		stack<int> score;
		score.push(0);
		for (auto c : S)
		{
			if (c == '(')
				score.push(0);
			else
			{
				int val0 = score.top();
				score.pop();
				int val1 = score.top();
				score.pop();
				score.push(val1 + max(val0 << 1, 1));
			}
		}
		return score.top();
	}
};