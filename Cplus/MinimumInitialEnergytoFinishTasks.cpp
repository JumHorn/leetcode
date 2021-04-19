#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumEffort(vector<vector<int>> &tasks)
	{
		auto f = [&](vector<int> &lhs, vector<int> &rhs) {
			return lhs[0] + rhs[1] < rhs[0] + lhs[1];
		};
		sort(tasks.begin(), tasks.end(), f);
		int res = 0, cur = 0;
		for (auto &task : tasks)
		{
			if (cur < task[1])
			{
				res += task[1] - cur;
				cur = task[1];
			}
			cur -= task[0];
		}
		return res;
	}
};