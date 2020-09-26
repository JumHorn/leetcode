#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int eraseOverlapIntervals(vector<vector<int>> &intervals)
	{
		sort(intervals.begin(), intervals.end(), *this);
		if (intervals.empty())
			return 0;
		int res = 1, maxright = intervals[0][1], N = intervals.size();
		for (int i = 1; i < N; ++i)
		{
			if (intervals[i][0] >= maxright)
			{
				++res;
				maxright = intervals[i][1];
			}
		}
		return N - res;
	}

	bool operator()(const vector<int> &lhs, const vector<int> &rhs)
	{
		return lhs[1] < rhs[1];
	}
};