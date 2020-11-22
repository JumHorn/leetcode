#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumEffort(vector<vector<int>> &tasks)
	{
		int N = tasks.size();
		auto f = [&](vector<int> &lhs, vector<int> &rhs) {
			return lhs[0] + rhs[1] < rhs[0] + lhs[1];
		};
		sort(tasks.begin(), tasks.end(), f);
		int res = 0, cur = 0;
		for (int i = 0; i < N; ++i)
		{
			if (cur < tasks[i][1])
			{
				res += tasks[i][1] - cur;
				cur += tasks[i][1] - cur;
			}
			cur -= tasks[i][0];
		}
		return res;
	}
};