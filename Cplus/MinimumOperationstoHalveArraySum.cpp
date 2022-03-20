#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int halveArray(vector<int> &nums)
	{
		priority_queue<double> q;
		int res = 0;
		double sum = 0;
		for (auto n : nums)
		{
			q.push(n);
			sum += n;
		}
		double target = sum / 2.0;
		while (sum > target)
		{
			++res;
			double val = q.top();
			q.pop();
			sum -= val / 2;
			q.push(val / 2);
		}
		return res;
	}
};