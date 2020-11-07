#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int largestRectangleArea(vector<int> &heights)
	{
		stack<int> s;
		s.push(-1);
		int res = 0, N = heights.size();
		for (int i = 0; i < N; ++i)
		{
			while (s.size() > 1u && heights[i] <= heights[s.top()])
			{
				int pre = s.top();
				s.pop();
				res = max(res, heights[pre] * (i - s.top() - 1));
			}
			s.push(i);
		}

		for (int right = s.top() + 1; s.size() > 1u;)
		{
			int pre = s.top();
			s.pop();
			res = max(res, heights[pre] * (right - s.top() - 1));
		}
		return res;
	}
};