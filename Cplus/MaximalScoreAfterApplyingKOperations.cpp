#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	long long maxKelements(vector<int> &nums, int k)
	{
		priority_queue<int> q;
		for (auto n : nums)
			q.push(n);
		long long res = 0;
		while (--k >= 0)
		{
			int n = q.top();
			q.pop();
			res += n;
			q.push((n + 2) / 3);
		}
		return res;
	}
};