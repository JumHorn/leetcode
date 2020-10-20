#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestWPI(vector<int> &hours)
	{
		int N = hours.size(), res = 0;
		vector<int> prefixsum(N + 1);
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] = prefixsum[i] + (hours[i] > 8 ? 1 : -1);
		stack<int> s; //decreasing stack with value's index
		s.push(0);
		for (int i = 0; i <= N; ++i)
		{
			if (prefixsum[i] < prefixsum[s.top()])
				s.push(i);
		}
		for (int i = N; i >= 0; --i)
		{
			while (!s.empty() && prefixsum[i] - prefixsum[s.top()] >= 1)
			{
				res = max(res, i - s.top());
				s.pop();
			}
		}
		return res;
	}
};