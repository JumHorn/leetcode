#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumDeviation(vector<int> &nums)
	{
		priority_queue<int> q;
		int lower = INT_MAX, upper = INT_MIN, res = 0;
		for (auto n : nums)
		{
			if (n & 1) //odd value can only multi once
				n <<= 1;
			q.push(n);
			lower = min(lower, n);
			upper = max(upper, n);
		}
		res = upper - lower;
		while (q.top() % 2 == 0)
		{
			upper = q.top();
			res = min(res, upper - lower);
			q.pop();
			upper >>= 1;
			lower = min(lower, upper);
			q.push(upper);
		}
		return min(res, q.top() - lower);
	}
};