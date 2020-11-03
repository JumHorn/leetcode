#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeCoveredIntervals(vector<vector<int>> &intervals)
	{
		int res = 0, n = intervals.size();
		sort(intervals.begin(), intervals.end(), *this);
		for (int i = 1, j = 0; i < n; ++i)
		{
			if (intervals[j][1] >= intervals[i][1])
				res++;
			else
				j = i;
		}
		return n - res;
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		if (lhs[0] != rhs[0])
			return lhs[0] < rhs[0];
		return lhs[1] > rhs[1];
	}
};
