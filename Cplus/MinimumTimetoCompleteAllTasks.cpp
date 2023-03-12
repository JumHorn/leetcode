#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int findMinimumTime(vector<vector<int>> &tasks)
	{
		const int SIZE = 2001;
		vector<int> run(SIZE); // which time is on
		int res = 0;
		sort(tasks.begin(), tasks.end(), [](vector<int> &lhs, vector<int> &rhs)
			 { return lhs[1] < rhs[1]; });
		for (auto &t : tasks)
		{
			int start = t[0], end = t[1], d = t[2];
			for (int i = start; i <= end; ++i)
				d -= run[i];
			for (int i = end; d > 0; --i)
			{
				if (run[i] == 0)
				{
					--d;
					run[i] = 1;
					++res;
				}
			}
		}
		return res;
	}
};