#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
	{
		vector<vector<int>> res;
		int i = 0, n = intervals.size();
		for (i = 0; i < n; i++)
		{
			if (newInterval[1] < intervals[i][0])
			{
				res.push_back(newInterval);
				res.push_back(intervals[i]);
				break;
			}
			if (newInterval[0] > intervals[i][1])
				res.push_back(intervals[i]);
			else
			{
				newInterval[0] = min(newInterval[0], intervals[i][0]);
				newInterval[1] = max(newInterval[1], intervals[i][1]);
			}
		}
		if (i == n)
			res.push_back(newInterval);
		else
		{
			while (++i < n)
				res.push_back(intervals[i]);
		}
		return res;
	}
};
